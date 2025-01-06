#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include "raylib.h"
#include "Menu.h"

class SettingsMenu : public Menu {
    public:
        void draw();
    private:
        int menuNumber = 2;
};

#endif
