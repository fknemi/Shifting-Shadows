#include <raylib.h>
#include "Player.h"
#include "levels/LevelOne.h"
int main() {
    const int screenWidth = 1280;
    const int screenHeight = 800;
    const int targetFPS = 60;

    InitWindow(screenWidth, screenHeight, "Shifting Shadows");
    Player player(screenWidth, screenHeight, screenWidth / 4, screenHeight / 2);
    SetTargetFPS(targetFPS);
    LevelOne l1;
    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        // Update player
        player.update(deltaTime);
        player.resetCollisions();
        // Move player
        if (IsKeyDown(KEY_LEFT)) {
            player.moveLeft();
        }
        if (IsKeyDown(KEY_RIGHT)) {
            player.moveRight();
        }
        if (IsKeyPressed(KEY_UP)) {
            player.jump();
        }
        if (IsKeyPressed(KEY_F11)){
            ToggleFullscreen();
        }
        Rectangle platforms = l1.getPlatforms();
        if(CheckCollisionRecs(platforms, player.getPosition())){
                  DrawText("Platform Collision", 1280/4, 200, 80, RED);
                  player.checkCollisions(false,true,platforms);
        }
        if(player.getPosition().y > 800){
            player.reset();
        }
        BeginDrawing();
        ClearBackground(BLACK);

        DrawFPS(10, 10);
        l1.drawPlatforms(); 
        player.draw();

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context
    return 0;
}
