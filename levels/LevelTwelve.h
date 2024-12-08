#include "Level.h"
#include "vector"
#include <raylib.h>

#ifndef LEVELTWELVE_H
#define LEVELTWELVE_H

#include "Level.h" // Make sure you're including the base class header

class LevelTwelve : public Level {
private:
  int stageCount = 12;
  std::vector<Rectangle> platforms;

public:
  LevelTwelve() {
    platforms.push_back({100, 200, 200, 10}); // Example platform
  }

  void drawPlatforms() override {
    for (const auto &platform : platforms) {
      DrawRectangleRec(platform, BLUE);
    }
  }

  std::vector<Rectangle> getPlatforms() override { return platforms; }

  void update() override {
    // Update logic specific to LevelTwelve
  }
};

#endif // LEVELTWELVE_H
