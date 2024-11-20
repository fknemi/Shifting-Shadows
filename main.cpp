#include <raylib.h>
#include "Player.h"
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
    LevelOne l1;
    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

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
        if(CheckCollisionRecs(platforms, player.getPosition())){
                  DrawText("Platform Collision", 1280/4, 200, 80, RED);
                  player.checkCollisions(false,true,platforms);
        }
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

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context
    return 0;
}
