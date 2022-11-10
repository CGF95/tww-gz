#include "menus/main_menu.h"
#include "menus/amount_menu.h"
#include "libtww/MSL_C/string.h"

#define LINE_NUM 4
#define MAX_BOMB_BAG_OPTIONS 3
#define MAX_QUIVER_OPTIONS 3
#define MAX_RUPEE_WALLET_OPTIONS 3
#define MAX_MAGIC_METER_OPTIONS 3

Cursor AmountMenu::cursor;
int g_bombType = 0;
int g_quiverType = 0;
int g_rupeeType = 0;
int g_magicType = 0;

Line lines[LINE_NUM] = {
    {"bomb bag", BOMB_BAG_INDEX, "Choose from 30, 60, or 99", false, nullptr, 
     MAX_BOMB_BAG_OPTIONS},
    {"quiver", QUIVER_INDEX, "Choose from 30, 60 or 99", false, nullptr, 
     MAX_QUIVER_OPTIONS},
    {"rupee wallet", RUPEE_INDEX, "Choose from 200, 1000 or 5000", false, nullptr, 
     MAX_RUPEE_WALLET_OPTIONS},
    {"magic meter", MAGIC_INDEX, "Choose from none, normal or double", false, nullptr, 
     MAX_MAGIC_METER_OPTIONS},
};

ListMember rupee_opt[MAX_RUPEE_WALLET_OPTIONS] = {
    "200", "1000", "5000",
};

ListMember magic_opt[MAX_MAGIC_METER_OPTIONS] = {
    "none", "normal", "double",
};

void AmountMenu::draw() {
    cursor.setMode(Cursor::MODE_LIST);

    if (GZ_getButtonTrig(GZPad::B)) {
        GZ_setMenu(GZ_INVENTORY_MENU);
        return;
    }

    switch (cursor.y) {
    case BOMB_BAG_INDEX:
        cursor.x = g_cursorColorType;
        cursor.move(MAX_BOMB_BAG_OPTIONS, LINE_NUM);

        if (cursor.y == BOMB_BAG_INDEX) {
            g_bombType = cursor.x;
        }
        break;
    case QUIVER_INDEX:
        break;
    case RUPEE_INDEX:
        break;
    case MAGIC_INDEX:
        break;
    default:
        cursor.move(0, LINE_NUM);
        break;
    }

    ListMember ammo_opt[MAX_BOMB_BAG_OPTIONS] = {
        "30", "60", "99",
    };

    tww_sprintf(lines[BOMB_BAG_INDEX].value, " <%s>", ammo_opt[g_bombType].member);

    GZ_drawMenuLines(lines, cursor.y, LINE_NUM);
}