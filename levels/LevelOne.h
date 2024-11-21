#include "vector"
#include <raylib.h>
struct Platform {
  float x;
  float y;
  float opacity;
  float width;
  float height;
  bool enabledCollision;
  bool isVisibleToPlayer;
  bool drawPlatform;

  // Constructor to initialize the struct
  Platform(int x, int y, float opacity, float width, float height,
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

  // Function to get the platform's rectangle
};

class LevelOne {
private:
  int stageCount = 1;
  std::vector<Rectangle> platforms;

public:
  LevelOne() { Platform(300, 600, 1.0, 600, 10, true); }
  void drawPlatforms() {
    Platform p1(300, 600, 1.0, 600, 10, true);
    Platform p2(300, 300, 1.0, 10, 600, true);
    platforms.push_back({300, 300, 10, 600});
    platforms.push_back({300, 600, 600, 10});

  }
  std::vector<Rectangle> getPlatforms() { return platforms; }
};
