#include "menu.h"
#include "libtww/d/com/d_com_inf_game.h"

enum PauseMenuSlots {
    SLOT_0,
    SLOT_1,
    SLOT_2,
    SLOT_3,
    SLOT_4,
    SLOT_5,
    SLOT_6,
    SLOT_7,
    SLOT_8,
    SLOT_9,
    SLOT_10,
    SLOT_11,
    SLOT_12,
    SLOT_13,
    SLOT_14,
    SLOT_15,
    SLOT_16,
    SLOT_17,
    SLOT_18,
    SLOT_19,
    SLOT_20,
    SLOT_21,
    SLOT_22,
    SLOT_23,
};

struct ItemLookup {
    enum ItemTable item_id;
    char name[40];
};

class PauseMenu : public Menu {
public:
    PauseMenu() : Menu() {}
    static void UpdateListIndex();
    static void draw();

    static Cursor cursor;
};