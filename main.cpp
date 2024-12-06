#include "Player.h"
#include "elements/inputs/Mouse.cpp"
#include "levels/LevelOne.h"
#include "settings/Keybinds.cpp"
#include <raylib.h>
#include "Menus/StartMenu.cpp"
int main() {
  const int screenWidth = 1280;
  const int screenHeight = 800;
  const int targetFPS = 60;
    Player player(screenWidth, screenHeight, (float)screenWidth / 4,
                (float)screenHeight / 2);
  Mouse mouse;
  LevelOne l1;
  StartMenu startMenu;
  InitWindow(screenWidth, screenHeight, "Shifting Shadows");
  SetTargetFPS(targetFPS);

   // Initialize camera
  Camera2D camera = {0};
  camera.target = (Vector2){player.getPosition().x + player.getPosition().width / 2, 
                            player.getPosition().y + player.getPosition().height / 2};
  camera.offset = (Vector2){screenWidth / 2, screenHeight / 2};
  camera.zoom = 1.0f;


  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();
    
    // Update player
    player.update(deltaTime);
    mouse.update();

    // Update camera target to follow the player
    camera.target = (Vector2){player.getPosition().x + player.getPosition().width / 2, 
                              player.getPosition().y + player.getPosition().height / 2};
    
    BeginDrawing();
    ClearBackground(BLACK);

  BeginMode2D(camera); // Apply the camera transformation

if(startMenu.getStatus() == false){
startMenu.draw();

}else{
          player.draw();
   mouse.draw();
}

if(startMenu.getStatus() && startMenu.getCurrentLevel() == 1){
 l1.drawPlatforms();
 
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
    if(IsKeyPressed(Keybinds["CONTINUE"].CurrentKeybind)){
      startMenu.hideMenu();

    }
    std::vector<Rectangle> platforms = l1.getPlatforms();
    for (Rectangle platform : platforms) {
      if (CheckCollisionRecs(platform, player.getPosition())) {
        DrawText("Platform Collision", screenWidth * 0.1, 200, 20, RED);
        player.checkCollisions(true, true, platform, deltaTime);
      }
    }
    if (player.getPosition().y > 800) {
      player.reset();
    }
    
    EndMode2D(); // End the camera transformation
    
    DrawFPS(10, 10);

    EndDrawing();
  }

  CloseWindow(); // Close window and OpenGL context
  return 0;
}
