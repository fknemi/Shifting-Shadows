#include "Level.h"
#include "vector"
#include <raylib.h>

#ifndef LEVELSIX_H
#define LEVELSIX_H

#include "Level.h" // Make sure you're including the base class header

class LevelSix : public Level {
private:
  int stageCount = 6;
  std::vector<Rectangle> platforms;

public:
  LevelSix() {
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

#endif // LEVELSIX_H