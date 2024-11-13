#include <raylib.h>

int main() {
  InitWindow(1280, 800, "Shifting Shadows");
  bool showText = false;
  SetTargetFPS(120);
  while (!WindowShouldClose()) {
    showText = IsKeyDown(KEY_SPACE);
    DrawFPS(10, 10);
    ClearBackground(BLACK);
    BeginDrawing();

    if (showText) {
      DrawText("Hello World", 200, 200, 80, RED);
      BeginDrawing();
    }

    EndDrawing();
  }
  return 0;
}
