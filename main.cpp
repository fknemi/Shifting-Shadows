#include <raylib.h>
#include "Player.h"

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 800;
    const int targetFPS = 60;

    InitWindow(screenWidth, screenHeight, "Shifting Shadows");
    Player player(screenWidth, screenHeight, screenWidth / 4, screenHeight / 2);
    SetTargetFPS(targetFPS);

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        // Update player
        player.update(deltaTime);

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
        BeginDrawing();
        ClearBackground(BLACK);

        DrawFPS(10, 10);
        player.draw();

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context
    return 0;
}
