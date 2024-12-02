#include <raylib.h>
struct Floor {
  float x;
  float y;
  float opacity;
  float width;
  float height;
  bool enabledCollision;
  bool isVisibleToPlayer;
  bool drawPlatform;

  // Constructor to initialize the struct
  Floor(int x, int y, float opacity, float width, float height,
           bool enabledCollision)
      : x(x), y(y), opacity(opacity), width(width), height(height),
        enabledCollision(enabledCollision), isVisibleToPlayer(true),
        drawPlatform(true) {
    if (drawPlatform) {
      draw();
    }
  }

  // Draw function to draw the platform
  void draw() { DrawRectangle(x, y, width, height, GREEN); }

};


