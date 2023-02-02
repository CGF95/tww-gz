#include "menus/main_menu.h"
#include "menus/pause_menu.h"

#define LINE_NUM 24
#define DEFAULT_BUTTON_TEXT "Z"
#define DEFAULT_BUTTON GZPad::Z
#define MAX_ITEMS 106

Cursor PauseMenu::cursor;

Line lines[LINE_NUM] = {
    {"Slot 0:",  SLOT_0,  "", false, nullptr, false},
    {"Slot 1:",  SLOT_1,  "", false, nullptr, false},
    {"Slot 2:",  SLOT_2,  "", false, nullptr, false},
    {"Slot 3:",  SLOT_3,  "", false, nullptr, false},
    {"Slot 4:",  SLOT_4,  "", false, nullptr, false},
    {"Slot 5:",  SLOT_5,  "", false, nullptr, false},
    {"Slot 6:",  SLOT_6,  "", false, nullptr, false},
    {"Slot 7:",  SLOT_7,  "", false, nullptr, false},
    {"Slot 8:",  SLOT_8,  "", false, nullptr, false},
    {"Slot 9:",  SLOT_9,  "", false, nullptr, false},
    {"Slot 10:", SLOT_10, "", false, nullptr, false},
    {"Slot 11:", SLOT_11, "", false, nullptr, false},
    {"Slot 12:", SLOT_12, "", false, nullptr, false},
    {"Slot 13:", SLOT_13, "", false, nullptr, false},
    {"Slot 14:", SLOT_14, "", false, nullptr, false},
    {"Slot 15:", SLOT_15, "", false, nullptr, false},
    {"Slot 16:", SLOT_16, "", false, nullptr, false},
    {"Slot 17:", SLOT_17, "", false, nullptr, false},
    {"Slot 18:", SLOT_18, "", false, nullptr, false},
    {"Slot 19:", SLOT_19, "", false, nullptr, false},
    {"Slot 20:", SLOT_20, "", false, nullptr, false},
    {"Slot 21:", SLOT_21, "", false, nullptr, false},
    {"Slot 22:", SLOT_22, "", false, nullptr, false},
    {"Slot 23:", SLOT_23, "", false, nullptr, false},
};

int listIndex = 0;

void PauseMenu::UpdateListIndex() {
}

void PauseMenu::draw() {
    cursor.setMode(Cursor::MODE_LIST);
    UpdateListIndex();

    if (GZ_getButtonTrig(GZPad::B)) {
        GZ_setMenu(GZ_INVENTORY_MENU);
        return;
    }

    if (GZ_getButtonTrig(GZPad::A)) {
        switch (cursor.y) {
            return;
        }
    }
}