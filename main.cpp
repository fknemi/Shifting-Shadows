#include "Player.h"
#include "elements/inputs/Mouse.cpp"
#include "levels/LevelOne.h"
#include "settings/Keybinds.cpp"
#include <raylib.h>
int main() {
  const int screenWidth = 1280;
  const int screenHeight = 800;
  const int targetFPS = 60;
  InitWindow(screenWidth, screenHeight, "Shifting Shadows");
  Player player(screenWidth, screenHeight, (float)screenWidth / 4,
                (float)screenHeight / 2);
  Mouse mouse;
  SetTargetFPS(targetFPS);
  LevelOne l1;
  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();
    
    // Update player
    player.update(deltaTime);
    l1.drawPlatforms();
    mouse.update();
    player.draw();
    mouse.draw();
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
    std::vector<Rectangle> platforms = l1.getPlatforms();
    for (Rectangle platform : platforms) {
      if (CheckCollisionRecs(platform, player.getPosition())) {
        DrawText("Platform Collision", 1280 / 4, 200, 80, RED);
        player.checkCollisions(true, true, platform);
      }
    }
    if (player.getPosition().y > 800) {
      player.reset();
    }

    BeginDrawing();
    ClearBackground(BLACK);

    DrawFPS(10, 10);

    EndDrawing();
  }

  CloseWindow(); // Close window and OpenGL context
  return 0;
}
