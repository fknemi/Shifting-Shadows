#include "Player.h"
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
#include "settings/Keybinds.cpp"
#include <raylib.h>
#include "levels/LevelOne.h"

int main() {
  const int screenWidth = 1280;
  const int screenHeight = 800;
  const int targetFPS = 60;
  InitWindow(screenWidth, screenHeight, "Shifting Shadows");
  Player player(screenWidth, screenHeight, (float)screenWidth / 4, (float)screenHeight / 2);
  SetTargetFPS(targetFPS);
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
    // Update player
    player.update(deltaTime);
    player.resetCollisions();
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

    BeginDrawing();
    ClearBackground(BLACK);
>>>>>>> aabba52 (updated Keybinds for player and added todo in Config.cpp, fixed collision for floor platform)

    DrawFPS(10, 10);
    player.draw();

    EndDrawing();
  }

  CloseWindow(); // Close window and OpenGL context
  return 0;
}
