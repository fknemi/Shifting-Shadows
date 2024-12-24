#include "Menus/StartMenu.cpp"
#include "Player.h"
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#include "LevelOne.h"

=======
#include "levels/LevelOne.h"
>>>>>>> 82ba856 (added floor platform with collision and collision methods to Player)
int main() {
    const int screenWidth = 1280;
    const int screenHeight = 800;
    const int targetFPS = 60;

    InitWindow(screenWidth, screenHeight, "Shifting Shadows");

    Player player(screenWidth, screenHeight, screenWidth / 4, screenHeight - 50, "resources/player.png");
    LevelOne levelOne;

    SetTargetFPS(targetFPS);
=======
=======
=======
#include "elements/inputs/Button.h"
>>>>>>> dc95e91 (idk too much)
#include "elements/inputs/Mouse.cpp"
#include "elements/platforms/Floor.h"
#include "elements/platforms/Wall.h"
#include "levels/Level.h"
#include "levels/LevelEight.h"
#include "levels/LevelEleven.h"
#include "levels/LevelFive.h"
#include "levels/LevelFour.h"
#include "levels/LevelNine.h"
#include "levels/LevelOne.h"
<<<<<<< HEAD
>>>>>>> 9fe5fc9 (fixed player falling through floor when reset && updated LevelOne to use vector for platforms)
=======
#include "levels/LevelSeven.h"
#include "levels/LevelSix.h"
#include "levels/LevelTen.h"
#include "levels/LevelThree.h"
#include "levels/LevelTwelve.h"
#include "levels/LevelTwo.h"
<<<<<<< HEAD
>>>>>>> b847e32 (added files for all levels and removed broken texture causing seg fault)
=======
#include "settings/Config.cpp"
>>>>>>> dc95e91 (idk too much)
#include "settings/Keybinds.cpp"
#include <raylib.h>

int main() {
  const float screenWidth = 1280;
  const float screenHeight = 800;
  const int targetFPS = 60;
  Player *player = nullptr;
  Mouse mouse;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  SetTargetFPS(targetFPS);
<<<<<<< HEAD
>>>>>>> aabba52 (updated Keybinds for player and added todo in Config.cpp, fixed collision for floor platform)
    LevelOne l1;
  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();

<<<<<<< HEAD
        // Update player
        player.update(deltaTime);
<<<<<<< HEAD

        // Player movement
=======
        player.resetCollisions();
        // Move player
>>>>>>> 82ba856 (added floor platform with collision and collision methods to Player)
        if (IsKeyDown(KEY_LEFT)) {
            player.moveLeft();
        }
        if (IsKeyDown(KEY_RIGHT)) {
            player.moveRight();
        }
        if (IsKeyPressed(KEY_UP)) {
            player.jump();
        }
        if (IsKeyPressed(KEY_F11)) {
            ToggleFullscreen();
        }
<<<<<<< HEAD

=======
        Rectangle platforms = l1.getPlatforms();
=======
=======
=======
>>>>>>> 9ecd4bc (added basic start menu, added onGround to Player (not used))
  LevelOne l1;
=======
>>>>>>> b847e32 (added files for all levels and removed broken texture causing seg fault)
  StartMenu startMenu;
=======
>>>>>>> dc95e91 (idk too much)
  Level *level = nullptr;
  Config config;

  InitWindow(screenWidth, screenHeight, "Shifting Shadows");
  SetTargetFPS(targetFPS);

  // Initialize camera
  Camera2D camera = {0};
  camera.offset = (Vector2){screenWidth / 2, screenHeight / 2};
  camera.zoom = 1.0f;
  StartMenu startMenu;
  Button settingsBtn =
      Button("assets/menu/settings.png",
             {-screenWidth * (float)0.1, screenHeight * (float)0.001}, 0.8);
  Button selectLevelBtn =
      Button("assets/menu/select-level.png",
             {-screenWidth * (float)0.1, -screenHeight * (float)0.15}, 0.8);
  Button *muteBtn =
      new Button("assets/menu/unmute.png",
                 {screenWidth * (float)0.43, screenHeight * (float)0.4}, 0.8);
  Button *unmuteBtn =
      new Button("assets/menu/mute.png",
                 {screenWidth * (float)0.43, screenHeight * (float)0.4}, 0.8);

  Button exitBtn =
      Button("assets/menu/exit.png",
             {-screenWidth * (float)0.1, screenHeight * (float)0.35}, 0.8);
  Button backBtn =
      Button("assets/menu/back.png",
             {-screenWidth * (float)0.1, -screenHeight * (float)0.15}, 0.8);
  Button title =
      Button("assets/menu/title.png",
             {-screenWidth * (float)0.2, -screenHeight * (float)0.5}, 0.8);
   Button platform   =
      Button("assets/LevelOne/platform.png",
             {0,0}, 0.8);
   
  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();
<<<<<<< HEAD
    
>>>>>>> 9fe5fc9 (fixed player falling through floor when reset && updated LevelOne to use vector for platforms)
=======

>>>>>>> b847e32 (added files for all levels and removed broken texture causing seg fault)
    // Update player
    BeginDrawing();
    ClearBackground(LIGHTGRAY);

    BeginMode2D(camera); // Apply the camera transformation

    // startMenu.getStatus() if false player is in menu
    if (startMenu.getStatus() == 0) {
      selectLevelBtn.draw();
      settingsBtn.draw();
      exitBtn.draw();
      muteBtn->draw();
      title.draw();
      bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
      Vector2 mousePos = GetMousePosition();
      DrawCircle(mousePos.x, mousePos.y, 5,
                 BLUE); // Visualize the mouse position
      if (exitBtn.isPressed(mousePos, mousePressed)) {
        CloseWindow();
        return 0;
      }
      if (settingsBtn.isPressed(mousePos, mousePressed)) {
      }

      if (muteBtn->isPressed(mousePos, mousePressed)) {
        if (config.Audio["MasterVolume"] > 0) {
          // Set volume to 0 and switch to mute button
          config.Audio["MasterVolume"] = 0;
          std::swap(muteBtn, unmuteBtn);
        } else {
          // Restore volume and switch to unmute button
          config.Audio["MasterVolume"] = 0.8f;
          std::swap(muteBtn, unmuteBtn);
        }
      }
      if (selectLevelBtn.isPressed(mousePos, mousePressed)) {
        startMenu.hideMenu();
      }
    }
    // startMenu.getStatus() if 4 player then the game is started
    if (startMenu.getStatus() == 3) {
      player = new Player(screenWidth, screenHeight, (float)screenWidth / 4,
                          (float)screenHeight / 2);

      camera.target =
          (Vector2){player->getPosition().x + player->getPosition().width / 2,
                    player->getPosition().y + player->getPosition().height / 2};
      player->update(deltaTime);
      mouse.update();
      player->draw();
      mouse.draw();
  
      switch (startMenu.getCurrentLevel()) {
      case 1:
        level = new LevelOne();
        platform.draw();
 

             break;
      case 2:
        level = new LevelTwo();
        break;
      case 3:
        level = new LevelThree();
        break;
      case 4:
        level = new LevelFour();
        break;
      case 5:
        level = new LevelFive();
        break;
      case 6:
        level = new LevelSix();
        break;
      case 7:
        level = new LevelSeven();
        break;
      case 8:
        level = new LevelEight();
        break;
      case 9:
        level = new LevelNine();
        break;
      case 10:
        level = new LevelTen();
        break;
      case 11:
        level = new LevelEleven();
        break;
      case 12:
        level = new LevelTwelve();
        break;
      }

      std::vector<Rectangle> platforms = level->getPlatforms();
      for (Rectangle platform : platforms) {
        if (CheckCollisionRecs(platform, player->getPosition())) {
          DrawText("Platform Collision", screenWidth * 0.1, 200, 20, RED);
          player->checkCollisions(true, true, platform, deltaTime);
        }
      }
      if (player->getPosition().y > 800) {
        player->reset();
      }

      if (IsKeyDown(Keybinds["MOVE LEFT"].CurrentKeybind)) {
        player->moveLeft();
      }
      if (IsKeyDown(Keybinds["MOVE RIGHT"].CurrentKeybind)) {
        player->moveRight();
      }
      if (IsKeyPressed(Keybinds["JUMP"].CurrentKeybind)) {
        player->jump();
      }
      if (IsKeyPressed(Keybinds["TOGGLE FULLSCREEN"].CurrentKeybind)) {
        ToggleFullscreen();
      }
      if (IsKeyPressed(Keybinds["CAMOUFLAGE"].CurrentKeybind)) {
      }
      if (IsKeyPressed(Keybinds["USE TONGUE"].CurrentKeybind)) {
      }
      if (IsKeyPressed(Keybinds["GRAB TONGUE"].CurrentKeybind)) {
      }
    }
<<<<<<< HEAD
    // Move player
    if (IsKeyDown(Keybinds["MOVE LEFT"].CurrentKeybind)) {
      player.moveLeft();
    }
    if (IsKeyDown(Keybinds["MOVE RIGHT"].CurrentKeybind)) {
      player.moveRight();
    }
    if (IsKeyPressed(Keybinds["JUMP"].CurrentKeybind)) {
      player.jump();
    }
    if (IsKeyPressed(Keybinds["TOGGLE FULLSCREEN"].CurrentKeybind)) {
      ToggleFullscreen();
    }
<<<<<<< HEAD
    if (IsKeyPressed(Keybinds["CAMOUFLAGE"].CurrentKeybind)) {}
    if (IsKeyPressed(Keybinds["USE TONGUE"].CurrentKeybind)) {}
    if (IsKeyPressed(Keybinds["GRAB TONGUE"].CurrentKeybind)) {}

      Rectangle platforms = l1.getPlatforms();
>>>>>>> aabba52 (updated Keybinds for player and added todo in Config.cpp, fixed collision for floor platform)
        if(CheckCollisionRecs(platforms, player.getPosition())){
                  DrawText("Platform Collision", 1280/4, 200, 80, RED);
                  player.checkCollisions(false,true,platforms);
        }
<<<<<<< HEAD
        if(player.getPosition().y > 800){
            player.reset();
        }
>>>>>>> 82ba856 (added floor platform with collision and collision methods to Player)
        BeginDrawing();
        ClearBackground(DARKGRAY);

        // Draw the level and player
        levelOne.draw();
        player.draw();

        DrawFPS(10, 10);
<<<<<<< HEAD
=======
        l1.drawPlatforms(); 
        player.draw();
>>>>>>> 82ba856 (added floor platform with collision and collision methods to Player)
=======
=======
    if (IsKeyPressed(Keybinds["CAMOUFLAGE"].CurrentKeybind)) {
    }
    if (IsKeyPressed(Keybinds["USE TONGUE"].CurrentKeybind)) {
    }
    if (IsKeyPressed(Keybinds["GRAB TONGUE"].CurrentKeybind)) {
    }
=======

    // Move play->r

>>>>>>> 75c22ef (fixed camera following player initally, added assets for levels 1-4)
    if (IsKeyPressed(Keybinds["CONTINUE"].CurrentKeybind)) {
      startMenu.hideMenu();
    }
<<<<<<< HEAD
    std::vector<Rectangle> platforms = level->getPlatforms();
    for (Rectangle platform : platforms) {
      if (CheckCollisionRecs(platform, player.getPosition())) {
        DrawText("Platform Collision", screenWidth * 0.1, 200, 20, RED);
        player.checkCollisions(true, true, platform, deltaTime);
      }
    }
    if (player.getPosition().y > 800) {
      player.reset();
    }
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 9fe5fc9 (fixed player falling through floor when reset && updated LevelOne to use vector for platforms)

    BeginDrawing();
    ClearBackground(BLACK);
>>>>>>> aabba52 (updated Keybinds for player and added todo in Config.cpp, fixed collision for floor platform)

=======
    
    EndMode2D(); // End the camera transformation
    
>>>>>>> 517c71c (2D camera update)
=======
=======
>>>>>>> 091db9e (updated stageCount for all levels, fixed seg fault due to platforms in main.cpp)

    EndMode2D(); // End the camera transformation

>>>>>>> b847e32 (added files for all levels and removed broken texture causing seg fault)
    DrawFPS(10, 10);

    EndDrawing();
  }

  CloseWindow(); // Close window and OpenGL context
  return 0;
}
