#include "StartMenu.h"
#include <raylib.h>

void StartMenu::draw() {
 }
int StartMenu::getCurrentLevel() { return currentLevel; }
void StartMenu::showMenu(int menuNumber) { 
menuNumber = menuNumber;
}
void StartMenu::hideMenu(){
    menuNumber = 4;
}
bool StartMenu::getStatus() { return menuNumber; }
