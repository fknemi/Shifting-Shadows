#ifndef MENU_H
#define MENU_H

class Menu {
    private:
        int menuNumber = 4;
        int currentLevel = 2;
        int maxLevel = 12;
    public:
        int screenWidth = 800;
        int screenHeight = 1200;


        bool isMenuVisible = false;
        void changeMenu(int num = 0);
        bool hideMenu();
        bool showMenu();
        int getCurrentLevel();
        int getCurrentMenu();

};

#endif
