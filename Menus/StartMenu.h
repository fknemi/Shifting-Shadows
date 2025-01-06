#ifndef STARTMENU_H
#define STARTMENU_H

#include "raylib.h"
#include "Menu.h"

class StartMenu : public Menu {
    public:
        StartMenu();
        void draw();
    private:
        int menuNumber = 0;



};

#endif
