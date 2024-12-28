

class Menu {
    private:
        bool showMenu = false;
        int menuNumber = 0;
        int currentLevel = 1;
        int maxLevel = 12;

    public:
        void changeMenu(int num = 0);
        void hideMenu();
        virtual void draw() = 0;
        int getCurrentLevel();

};
