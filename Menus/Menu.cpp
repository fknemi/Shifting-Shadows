#include "Menu.h"


void Menu::changeMenu(int num){
    menuNumber = num;
}

void Menu::hideMenu(){
    showMenu = false;
}
int Menu::getCurrentLevel() { return currentLevel; }

