#include "raylib.h"
#include "vector"
#include <raylib.h>
struct Wall {
  float x;
  float y;
  float opacity;
  float width;
  float height;
  bool enabledCollision;
  bool isVisibleToPlayer;
  bool drawPlatform;

  // Constructor to initialize the struct
  Wall(float x, float y, float opacity, float width, float height,
       bool enabledCollision, std::vector<Rectangle> *platforms)
      : x(x), y(y), opacity(opacity), width(width), height(height),
        enabledCollision(enabledCollision), isVisibleToPlayer(true),
        drawPlatform(true) {
    if (drawPlatform) {
      draw();
      platforms->push_back({x, y, width, height});
    }
  }

  // Draw function to draw the platform
  void draw() { DrawRectangle(x, y, width, height, GREEN); }
};
