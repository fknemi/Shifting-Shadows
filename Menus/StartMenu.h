#ifndef STARTMENU_H
#define STARTMENU_H

#include "raylib.h"

class StartMenu {
public:
  void draw();
  bool getStatus();
  void hideMenu();
  int getCurrentLevel();
  void showMenu(int menuNumber);
  
private:
  int menuNumber = 0;
  bool didStartGame = false;
  int currentLevel = 1;
  int maxLevel = 12;
};

#endif
