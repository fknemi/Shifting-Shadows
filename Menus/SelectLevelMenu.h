#ifndef SELECTLEVELMENU_H
#define SELECTLEVELMENU_H

#include "raylib.h"
#include "Menu.h"

class SelectLevelMenu : public Menu {
    public:
        void draw();
    private:
        int menuNumber = 1;
};

#endif
