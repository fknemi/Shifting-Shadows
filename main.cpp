#include "Menus/StartMenu.cpp"
#include "Player.h"
#include "elements/inputs/Button.h"
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
#include "settings/Config.cpp"
#include "settings/Keybinds.cpp"
#include <raylib.h>

int main() {
    const float screenWidth = 1280;
    const float screenHeight = 800;
    const int targetFPS = 60;
    Player *player = nullptr;
    Mouse mouse;
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



    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        // Update player
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        BeginMode2D(camera); // Apply the camera transformation

        
        if (startMenu.getCurrentMenu() == 0) {
            startMenu.showMenu();
            selectLevelBtn.draw();
            settingsBtn.draw();
            exitBtn.draw();
            muteBtn->draw();
            title.draw();
            bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
            Vector2 mousePos = GetMousePosition();

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
        if (startMenu.isMenuVisible == false) {
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

        // Move play->r

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
