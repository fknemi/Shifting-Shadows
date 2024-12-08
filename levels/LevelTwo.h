#include "Level.h"
#include "vector"
#include <raylib.h>

#ifndef LEVELTWO_H
#define LEVELTWO_H

#include "Level.h" // Make sure you're including the base class header

class LevelTwo : public Level {
private:
  int stageCount = 2;
  std::vector<Rectangle> platforms;

public:
  LevelTwo() {
    platforms.push_back({100, 200, 200, 10}); // Example platform
  }

  void drawPlatforms() override {
    for (const auto &platform : platforms) {
      DrawRectangleRec(platform, BLUE);
    }
  }

  std::vector<Rectangle> getPlatforms() override { return platforms; }

  void update() override {
    // Update logic specific to LevelTwo
  }
};

#endif // LEVELTWO_H
