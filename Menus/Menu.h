

class Menu {
    private:
                int menuNumber = 0;
        int currentLevel = 1;
        int maxLevel = 12;

    public:
bool isMenuVisible = true;

        void changeMenu(int num = 0);
        bool hideMenu();
        bool showMenu();
        virtual void draw() = 0;
        int getCurrentLevel();
        int getCurrentMenu();

};
