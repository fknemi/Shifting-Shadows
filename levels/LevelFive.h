#include "Level.h"
#include "vector"
#include <raylib.h>

#ifndef LEVELFIVE_H
#define LEVELFIVE_H

#include "Level.h" // Make sure you're including the base class header

class LevelFive : public Level {
private:
  int stageCount = 1;
  std::vector<Rectangle> platforms;

public:
  LevelFive () {
    platforms.push_back({100, 200, 200, 10}); // Example platform
  }

  void drawPlatforms() override {
    for (const auto &platform : platforms) {
      DrawRectangleRec(platform, BLUE);
    }
  }

  std::vector<Rectangle> getPlatforms() override { return platforms; }

  void update() override {
    // Update logic specific to LevelSix
  }
};

#endif // LEVELFIVE_H
