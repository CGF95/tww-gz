#include "menus/main_menu.h"
#include "menus/amount_menu.h"

#define LINE_NUM 4

Cursor AmountMenu::cursor;

Line lines[LINE_NUM] = {
    {"bomb bag", BOMB_BAG_INDEX, "Choose from 30, 60, or 99"},
    {"quiver", QUIVER_INDEX, "Choose from 30, 60 or 99"},
    {"rupee wallet", RUPEE_INDEX, "Choose from 200, 1000 or 5000"},
    {"rupee wallet", MAGIC_INDEX, "Choose from none, normal or double"},
};

void AmountMenu::draw() {
    cursor.move(0, LINE_NUM);

    if (GZ_getButtonTrig(GZPad::B)) {
        GZ_setMenu(GZ_INVENTORY_MENU);
        return;
    }

    if (GZ_getButtonTrig(GZPad::A)) {
        switch (cursor.y) {
        case BOMB_BAG_INDEX:
            return;
        case QUIVER_INDEX:
            return;
        case RUPEE_INDEX:
            return;
    }

    GZ_drawMenuLines(lines, cursor.y, LINE_NUM);
}