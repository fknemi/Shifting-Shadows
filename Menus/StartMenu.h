#ifndef STARTMENU_H
#define STARTMENU_H

class StartMenu {
public:
    void draw();
    bool getStatus();
    void hideMenu();
    int getCurrentLevel();
private:
    bool didStartGane = false;
    int currentLevel = 1;
    int maxLevel = 12;

};

#endif 
