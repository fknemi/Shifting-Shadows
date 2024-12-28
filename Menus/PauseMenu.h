#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "raylib.h"
#include "Menu.h"

class PauseMenu : public Menu {
    public:
        void draw();
    private:
        int menuNumber = 3;
};

#endif
