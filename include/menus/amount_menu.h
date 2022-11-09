#include "menu.h"

enum AmountMenuIndex {
    BOMB_BAG_INDEX,
    QUIVER_INDEX,
    RUPEE_INDEX,
    MAGIC_INDEX,
};

class AmountMenu : public Menu {
public:
    AmountMenu() : Menu() {}
    static void draw();

    static Cursor cursor;
};