#ifndef MENU_H
#define MENU_H

class Menu {
    private:
        int menuNumber = 0;
        int currentLevel = 1;
        int maxLevel = 12;
    public:
        int screenWidth = 800;
        int screenHeight = 1200;


        bool isMenuVisible = true;
        void changeMenu(int num = 0);
        bool hideMenu();
        bool showMenu();
        int getCurrentLevel();
        int getCurrentMenu();

};

#endif
