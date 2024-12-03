#include "Settings.h"
#include <raylib.h>

void Settings::update() {
    ClearBackground(BLACK);
    DrawText("Settings", 600, 200, 40, WHITE);
    DrawText("Press B to Go Back", 600, 400, 20, WHITE);
}

bool Settings::goBack() {
    return IsKeyPressed(KEY_B);
}
