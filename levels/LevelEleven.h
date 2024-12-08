#include "Level.h"
#include "vector"
#include <raylib.h>

#ifndef LEVELELEVEN_H
#define LEVELELEVEN_H

#include "Level.h" // Make sure you're including the base class header

class LevelEleven : public Level {
private:
  int stageCount = 1;
  std::vector<Rectangle> platforms;

public:
  LevelEleven() {
    platforms.push_back({100, 200, 200, 10}); // Example platform
  }

  void drawPlatforms() override {
    for (const auto &platform : platforms) {
      DrawRectangleRec(platform, BLUE);
    }
  }

  std::vector<Rectangle> getPlatforms() override { return platforms; }

  void update() override {
    // Update logic specific to LevelEleven
  }
};

#endif // LEVELELEVEN_H
