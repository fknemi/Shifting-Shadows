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
  void drawPlatforms() {
    Platform p1(300, 400, 1.0, 300, 10, true);
    platforms.push_back({300, 400, 300, 10});
    Platform p2(200, 500, 1.0, 200, 10, true);
    platforms.push_back({200, 500, 200, 10});
    Platform p3(300, 600, 1.0, 400, 10, true);
    platforms.push_back({300, 600, 400, 10});
    Platform p4(300, 300, 1.0, 10, 600, true);
    platforms.push_back({300, 300, 10, 600});
    Platform p5(800, 300, 1.0, 10, 600, true);
    platforms.push_back({800, 300, 10, 600});




  }
  std::vector<Rectangle> getPlatforms() { return platforms; }
};
