#include "Menus/StartMenu.cpp"
#include "Player.h"
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
#include "levels/LevelSeven.h"
#include "levels/LevelSix.h"
#include "levels/LevelTen.h"
#include "levels/LevelThree.h"
#include "levels/LevelTwelve.h"
#include "levels/LevelTwo.h"
#include "settings/Keybinds.cpp"
#include <raylib.h>

int main() {
  const float screenWidth = 1280;
  const float screenHeight = 800;
  const int targetFPS = 60;
  Player player(screenWidth, screenHeight, (float)screenWidth / 4,
                (float)screenHeight / 2);
  Mouse mouse;
  StartMenu startMenu;
  Level *level = nullptr;

  InitWindow(screenWidth, screenHeight, "Shifting Shadows");
  SetTargetFPS(targetFPS);

  // Initialize camera
  Camera2D camera = {0};
  camera.target =
      (Vector2){player.getPosition().x + player.getPosition().width / 2,
                player.getPosition().y + player.getPosition().height / 2};
  camera.offset = (Vector2){screenWidth / 2, screenHeight / 2};
  camera.zoom = 1.0f;

  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();

    // Update player
    player.update(deltaTime);
    mouse.update();

    // Update camera target to follow the player
    camera.target =
        (Vector2){player.getPosition().x + player.getPosition().width / 2,
                  player.getPosition().y + player.getPosition().height / 2};

    BeginDrawing();
    ClearBackground(BLACK);

    BeginMode2D(camera); // Apply the camera transformation

    if (startMenu.getStatus() == false) {
      startMenu.draw();

    } else {
      player.draw();
      mouse.draw();
    }
    if (startMenu.getStatus()) {
      switch (startMenu.getCurrentLevel()) {
      case 1:
        level = new LevelOne();
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
        if (CheckCollisionRecs(platform, player.getPosition())) {
          DrawText("Platform Collision", screenWidth * 0.1, 200, 20, RED);
          player.checkCollisions(true, true, platform, deltaTime);
        }
      }
      if (player.getPosition().y > 800) {
        player.reset();
      }
    }
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
    if (IsKeyPressed(Keybinds["CAMOUFLAGE"].CurrentKeybind)) {
    }
    if (IsKeyPressed(Keybinds["USE TONGUE"].CurrentKeybind)) {
    }
    if (IsKeyPressed(Keybinds["GRAB TONGUE"].CurrentKeybind)) {
    }
    if (IsKeyPressed(Keybinds["CONTINUE"].CurrentKeybind)) {
      startMenu.hideMenu();
    }

    EndMode2D(); // End the camera transformation

    DrawFPS(10, 10);

    EndDrawing();
  }

  CloseWindow(); // Close window and OpenGL context
  return 0;
}
