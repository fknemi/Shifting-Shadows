#include "Menus/StartMenu.cpp"
#include "Menus/PauseMenu.cpp"
#include "Menus/SelectLevelMenu.cpp"
#include "Menus/SettingsMenu.cpp"
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
#include "settings/Keybinds.cpp"
#include <raylib.h>

int main() {
    const float screenWidth = 1280;
    const float screenHeight = 800;
    const int targetFPS = 80;
    Player *player = nullptr;
    Mouse mouse;
    Level *level = nullptr;
    Config config;
    Menu menu;
    StartMenu startMenu;
    PauseMenu pauseMenu; 
    SelectLevelMenu selectLevelMenu;
    SettingsMenu settingsMenu;
    InitWindow(screenWidth, screenHeight, "Shifting Shadows");
    SetTargetFPS(targetFPS);

    // Initialize camera
    Camera2D camera = {0, 0};
    camera.zoom = 1.0f;



    Button *settingsBtn =
        new Button("assets/menu/settings.png",
                {screenWidth * (float)0.4, screenHeight *(float)0.6}, 0.8);
    Button *selectLevelBtn =
        new Button("assets/menu/select-level.png",
                {screenWidth * (float)0.4, screenHeight * (float)0.5}, 0.8);
    Button *muteBtn =
        new Button("assets/menu/unmute.png",
                {screenWidth * (float)0.95, screenHeight * (float)0.92}, 0.8);
    Button *unmuteBtn =
        new Button("assets/menu/mute.png",
                {screenWidth * (float)0.95, screenHeight * (float)0.92}, 0.8);

    Button *exitBtn =
        new Button("assets/menu/exit.png",
                {screenWidth * (float)0.4, screenHeight * (float)0.90}, 0.8);
    Button *backBtn =
        new Button("assets/menu/back.png",
                {screenWidth * (float)0.4, screenHeight * (float)0.8}, 0.8);
    Button *title =
        new Button("assets/menu/title.png",
                {screenWidth * (float)0.3, screenHeight * (float)0.1}, 1);
    Button *levelOneBtn =
        new Button("assets/menu/1.png",
                {screenWidth * (float)0.3, screenHeight * (float)0.1}, 1);
    Button *levelTwoBtn =
        new Button("assets/menu/2.png",
                {screenWidth * (float)0.4, screenHeight * (float)0.1}, 1);

    Button *levelThreeBtn =
        new Button("assets/menu/3.png",
                {screenWidth * (float)0.5, screenHeight * (float)0.1}, 1);
    Button *levelFourBtn =
        new Button("assets/menu/4.png",
                {screenWidth * (float)0.6, screenHeight * (float)0.1}, 1);
    Button *levelLocked5 =
        new Button("assets/menu/locked.png",
                {screenWidth * (float)0.3, screenHeight * (float)0.3}, 1);
    Button *levelLocked6 =
        new Button("assets/menu/locked.png",
                {screenWidth * (float)0.4, screenHeight * (float)0.3}, 1);

    Button *levelLocked7 =
        new Button("assets/menu/locked.png",
                {screenWidth * (float)0.5, screenHeight * (float)0.3}, 1);
    Button *levelLocked8 =
        new Button("assets/menu/locked.png",
                {screenWidth * (float)0.6, screenHeight * (float)0.3}, 1);
    Button *levelLocked9 =
        new Button("assets/menu/locked.png",
                {screenWidth * (float)0.3, screenHeight * (float)0.5}, 1);

    Button *levelLocked10 =
        new Button("assets/menu/locked.png",
                {screenWidth * (float)0.4, screenHeight * (float)0.5}, 1);


    Button *levelLocked11 =
        new Button("assets/menu/locked.png",
                {screenWidth * (float)0.5, screenHeight * (float)0.5}, 1);


    Button *levelLocked12 =
        new Button("assets/menu/locked.png",
                {screenWidth * (float)0.6, screenHeight * (float)0.5}, 1);



    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        // Update player
        BeginDrawing();
        ClearBackground((Color){198, 233, 241, 255});

        BeginMode2D(camera); // Apply the camera transformation
        mouse.update();
        mouse.draw();

        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        Vector2 mousePos = GetMousePosition();

        if(player){

            DrawFPS(10, 10);

            player->update(deltaTime);
            mouse.update();
            player->draw();
            mouse.draw();
        }

        if(menu.isMenuVisible && backBtn && backBtn->isPressed(mousePos,mousePressed)){
            int currentMenu = menu.getCurrentMenu();
            menu.changeMenu(currentMenu == 0 ? 0: currentMenu - 1);

        }
        if (menu.getCurrentMenu() == 0) {

            settingsBtn =
                new Button("assets/menu/settings.png",
                        {screenWidth * (float)0.4, screenHeight *(float)0.6}, 0.8);
            selectLevelBtn =
                new Button("assets/menu/select-level.png",
                        {screenWidth * (float)0.4, screenHeight * (float)0.5}, 0.8);
            muteBtn =
                new Button("assets/menu/unmute.png",
                        {screenWidth * (float)0.95, screenHeight * (float)0.92}, 0.8);
            unmuteBtn =
                new Button("assets/menu/mute.png",
                        {screenWidth * (float)0.95, screenHeight * (float)0.92}, 0.8);

            exitBtn =
                new Button("assets/menu/exit.png",
                        {screenWidth * (float)0.4, screenHeight * (float)0.90}, 0.8);

            title =
                new Button("assets/menu/title.png",
                        {screenWidth * (float)0.3, screenHeight * (float)0.1}, 1);

            startMenu.showMenu();
            selectLevelBtn->draw();
            settingsBtn->draw();
            exitBtn->draw();
            muteBtn->draw();
            title->draw();

            if (exitBtn->isPressed(mousePos, mousePressed)) {
                CloseWindow();
            }

            if (settingsBtn->isPressed(mousePos, mousePressed)) {
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
            if (selectLevelBtn->isPressed(mousePos, mousePressed)) {
                delete settingsBtn;
                delete selectLevelBtn;
                delete exitBtn;
                delete title;
                startMenu.hideMenu();
                menu.changeMenu(1);
                selectLevelMenu.showMenu();
                selectLevelMenu.draw();
            }




        } else if(menu.getCurrentMenu() == 1){
            levelOneBtn =
                new Button("assets/menu/1.png",
                        {screenWidth * (float)0.3, screenHeight * (float)0.1}, 1);
            levelTwoBtn =
                new Button("assets/menu/2.png",
                        {screenWidth * (float)0.4, screenHeight * (float)0.1}, 1);

            levelThreeBtn =
                new Button("assets/menu/3.png",
                        {screenWidth * (float)0.5, screenHeight * (float)0.1}, 1);
            levelFourBtn =
                new Button("assets/menu/4.png",
                        {screenWidth * (float)0.6, screenHeight * (float)0.1}, 1);

            levelLocked5 =
                new Button("assets/menu/locked.png",
                        {screenWidth * (float)0.3, screenHeight * (float)0.3}, 1);



            levelLocked6 =
                new Button("assets/menu/locked.png",
                        {screenWidth * (float)0.4, screenHeight * (float)0.3}, 1);

            levelLocked7 =
                new Button("assets/menu/locked.png",
                        {screenWidth * (float)0.5, screenHeight * (float)0.3}, 1);
            levelLocked8 =
                new Button("assets/menu/locked.png",
                        {screenWidth * (float)0.6, screenHeight * (float)0.3}, 1);
            levelLocked9 =
                new Button("assets/menu/locked.png",
                        {screenWidth * (float)0.3, screenHeight * (float)0.5}, 1);

            levelLocked10 =
                new Button("assets/menu/locked.png",
                        {screenWidth * (float)0.4, screenHeight * (float)0.5}, 1);

            levelLocked11 =
                new Button("assets/menu/locked.png",
                        {screenWidth * (float)0.5, screenHeight * (float)0.5}, 1);


            levelLocked12 =
                new Button("assets/menu/locked.png",
                        {screenWidth * (float)0.6, screenHeight * (float)0.5}, 1);



            levelOneBtn->draw();
            levelTwoBtn->draw();
            levelThreeBtn->draw();
            levelFourBtn->draw();
            backBtn->draw();
            levelLocked5->draw();
            levelLocked6->draw();
            levelLocked7->draw();
            levelLocked8->draw();
            levelLocked9->draw();
            levelLocked10->draw();
            levelLocked11->draw();
            levelLocked12->draw();
            if (levelOneBtn->isPressed(mousePos, mousePressed)) {
                menu.changeCurrentLevel(1);
                menu.hideMenu();
                menu.changeMenu(4);
            }
            if (levelTwoBtn->isPressed(mousePos, mousePressed)) {

                menu.changeCurrentLevel(2);

                menu.hideMenu();
                menu.changeMenu(4);

            }
            if (levelThreeBtn->isPressed(mousePos, mousePressed)) {
                menu.changeCurrentLevel(3);

                menu.hideMenu();
                menu.changeMenu(4);

            }
            if (levelFourBtn->isPressed(mousePos, mousePressed)) {
                menu.changeCurrentLevel(4);

                menu.hideMenu();
                menu.changeMenu(4);

            }


        } else if(menu.getCurrentMenu() == 2){
            settingsMenu.draw();
        } else if(menu.getCurrentMenu() == 3){
            pauseMenu.draw();
        }


        if (!menu.isMenuVisible) {
            if(!player){
                player = new Player(screenWidth, screenHeight, 100, 100);
            }
            if(player->shouldCameraFollow){
                float targetX = player->getPosition().x;
                float targetY = player->getPosition().y;
                targetX = targetX < 642 ? 642 : targetX > 1480 ? 1480 : targetX;
                targetY = targetY < 400 ? 400 : targetY > 400 ? 400 : targetY;
                camera.target = (Vector2){ targetX, targetY };
                camera.offset = (Vector2){ screenWidth / 2.0f, screenHeight / 2.0f }; // Set the camera center to the middle of the screen

            }

            switch (menu.getCurrentLevel()) {
                case 1:
                    level = new LevelOne();
                    break;
                case 2:
                    level = new LevelTwo();
                    player->togglePlayerCamera();
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

            level->drawPlatforms();
            level->drawObjects();
            std::vector<Rectangle> platforms = level->getPlatforms();
            for (Rectangle platform : platforms) {
                if (CheckCollisionRecs(platform, player->getPosition())) {
                    player->checkCollisions(true, true, platform, deltaTime);
                }
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


        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context
    return 0;
}
