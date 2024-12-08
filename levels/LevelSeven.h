#include "Level.h"
#include "vector"
#include <raylib.h>

#ifndef LEVELSEVEN_H
#define LEVELSEVEN_H

#include "Level.h" // Make sure you're including the base class header

class LevelSeven : public Level {
private:
  int stageCount = 7;
  std::vector<Rectangle> platforms;

public:
  LevelSeven() {
    platforms.push_back({100, 200, 200, 10}); // Example platform
  }

  void drawPlatforms() override {
    for (const auto &platform : platforms) {
      DrawRectangleRec(platform, BLUE);
    }
  }

  std::vector<Rectangle> getPlatforms() override { return platforms; }

  void update() override {
    // Update logic specific to LevelSeven
  }
};

#endif // LEVELSEVEN_H
