#include "menus/menu_scene/include/scene_menu.h"
#include <cstdio>
#include "libtww/include/d/com/d_com_inf_game.h"
#include "gz_flags.h"
#include "rels/include/defines.h"
#include "menus/utils/menu_mgr.h"

KEEP_FUNC SceneMenu::SceneMenu(Cursor& cursor)
    : Menu(cursor),
      lines{
          {"wind direction", MODIFY_WIND_INDEX, "Change the current wind direction"},
          {"chart set", MODIFY_CHART_SET_INDEX, "Change the current chart set"},
          {"current hour", TIME_HOURS_INDEX, "Change the current hour"},
          {"current minute", TIME_MINUTES_INDEX, "Change the current minute"},
          {"current date", MODIFY_DATE_INDEX, "Change the current date/moon phase"},
      } {}

SceneMenu::~SceneMenu() {}

s16 windDirs[8] = {-0x8000, -0x6000, -0x4000, -0x2000, 0, 0x2000, 0x4000, 0x6000};

const char* get_wind_str() {
    s16 wind = dkankyo_getWindDir();
    switch (wind) {
    case 0:
        return "East";
    case 0x2000:
        return "South East";
    case 0x4000:
        return "South";
    case 0x6000:
        return "South West";
    case -0x8000:
        return "West";
    case -0x6000:
        return "North West";
    case -0x4000:
        return "North";
    case -0x2000:
        return "North East";
    default:
        return "East";
    };
}

void updateWindDir() {
    s16 wind_dir = dkankyo_getWindDir();

    u8 wIndex = 0;
    int eventWindCheck = g_env_light.mWind.mEvtWindSet;

    if (wind_dir == -32768) {
        wIndex = 0;
    } else if (wind_dir == -24576) {
        wIndex = 1;
    } else if (wind_dir == -16384) {
        wIndex = 2;
    } else if (wind_dir == -8192) {
        wIndex = 3;
    } else if (wind_dir == 0) {
        wIndex = 4;
    } else if (wind_dir == 8192) {
        wIndex = 5;
    } else if (wind_dir == 16384) {
        wIndex = 6;
    } else if (wind_dir == 24576) {
        wIndex = 7;
    }

    Cursor::moveListSimple(wIndex);
    if (wIndex == 255) {
        wIndex = 7;
    } else if (wIndex == 8) {
        wIndex = 0;
    }

    if (eventWindCheck != 0xFF) {
        dKyw_tact_wind_set_go();
        dkankyo_setWindDir(windDirs[wIndex]);
        dComIfGs_setWindX(g_env_light.mWind.mTactWindAngleX);
        dComIfGs_setWindY(g_env_light.mWind.mTactWindAngleY);
    } else {
        dkankyo_setWindDir(windDirs[wIndex]);
        dComIfGs_setWindX(g_env_light.mWind.mTactWindAngleX);
        dComIfGs_setWindY(g_env_light.mWind.mTactWindAngleY);
    }
}

void updateChartSet() {
    u8 chartSet = dComIfGs_getChartSet();
    Cursor::moveListSimple(chartSet);
    if (chartSet == 0xFF) {
        chartSet = 0;
    } else if (chartSet > 3) {
        chartSet = 3;
    }
    dComIfGs_setChartSet(chartSet);
}

void SceneMenu::draw() {
    cursor.setMode(Cursor::MODE_LIST);

    if (GZ_getButtonTrig(BACK_BUTTON)) {
        g_menuMgr->pop();
        return;
    }

    float current_time = dComIfGs_getTime();

    int current_hour = (int)current_time / 15;
    if (current_hour > 23) {
        current_hour = 0;
    }
    int current_minute = (int)((4.0f * current_time) - current_hour * 60);

    int date = dComIfGs_getDate();

    lines[TIME_HOURS_INDEX].printf(" <%d>", current_hour);
    lines[TIME_MINUTES_INDEX].printf(" <%d>", current_minute);
    lines[MODIFY_DATE_INDEX].printf(" <%d>", date);

    switch (cursor.y) {
    case MODIFY_WIND_INDEX:
        updateWindDir();
        break;
    case MODIFY_CHART_SET_INDEX:
        updateChartSet();
        break;
    case TIME_HOURS_INDEX:
        if (GZ_getButtonRepeat(GZPad::DPAD_RIGHT)) {
            dComIfGs_setTime(current_time + 15.0f);
        } else if (GZ_getButtonRepeat(GZPad::DPAD_LEFT)) {
            dComIfGs_setTime(current_time - 15.0f);
        }
        break;
    case TIME_MINUTES_INDEX:
        if (GZ_getButtonRepeat(GZPad::DPAD_RIGHT)) {
            dComIfGs_setTime(current_time + 0.25f);
        } else if (GZ_getButtonRepeat(GZPad::DPAD_LEFT)) {
            dComIfGs_setTime(current_time - 0.25f);
        }
        break;
    case MODIFY_DATE_INDEX:
        if (GZ_getButtonRepeat(GZPad::DPAD_RIGHT)) {
            dComIfGs_setDate(date + 1);
        } else if (GZ_getButtonRepeat(GZPad::DPAD_LEFT)) {
            dComIfGs_setDate(date - 1);
        }
        break;
    }

    if (current_time >= 360.0f) {
        dComIfGs_setTime(current_time - 360.0f);
    } else if (current_time < 0) {
        dComIfGs_setTime(current_time + 360.0f);
    }

    if (date > 6) {
        dComIfGs_setDate(0);
    } else if (date == 0xFFFF) {
        dComIfGs_setDate(6);
    }

    lines[MODIFY_WIND_INDEX].printf(" <%s>", get_wind_str());
    lines[MODIFY_CHART_SET_INDEX].printf(" <%d>", dComIfGs_getChartSet());

    cursor.move(0, MENU_LINE_NUM);
    GZ_drawMenuLines(lines, cursor.y, MENU_LINE_NUM);
}
