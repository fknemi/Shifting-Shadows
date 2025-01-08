#include "Menu.h"


void Menu::changeMenu(int num){
    menuNumber = num;
}
int Menu::getCurrentMenu(){
    return menuNumber;
}
bool Menu::hideMenu(){
    isMenuVisible = false;
    return true;
}

bool Menu::showMenu(){
    isMenuVisible = true;
    return true;
}

int Menu::getCurrentLevel() { return currentLevel; }

void Menu::changeCurrentLevel(int num){
    currentLevel = num;
}


