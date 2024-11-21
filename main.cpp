#include "Player.h"
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
    LevelOne l1;
  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();

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
        if(CheckCollisionRecs(platforms, player.getPosition())){
                  DrawText("Platform Collision", 1280/4, 200, 80, RED);
                  player.checkCollisions(false,true,platforms);
        }

    BeginDrawing();
    ClearBackground(BLACK);

    DrawFPS(10, 10);
    player.draw();

    EndDrawing();
  }

  CloseWindow(); // Close window and OpenGL context
  return 0;
}
