#include "StartMenu.h"
#include <raylib.h>

void StartMenu::draw() {
    if(didStartGane) return;
    DrawText("Shifting Shadows", 500, 200, 40, WHITE);
    DrawText("Press ENTER to Start", 500, 300, 20, WHITE);
    DrawText("Press S for Settings", 500, 350, 20, WHITE);
}
int StartMenu::getCurrentLevel(){
    return currentLevel;
}
void StartMenu::hideMenu(){
    didStartGane = true;
}
bool StartMenu::getStatus() {
    return didStartGane;
}

