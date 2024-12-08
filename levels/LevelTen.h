#include "Level.h"
#include "vector"
#include <raylib.h>

#ifndef LEVELTEN_H
#define LEVELTEN_H

#include "Level.h" // Make sure you're including the base class header

class LevelTen : public Level {
private:
  int stageCount = 1;
  std::vector<Rectangle> platforms;

public:
  LevelTen() {
    platforms.push_back({100, 200, 200, 10}); // Example platform
  }

  void drawPlatforms() override {
    for (const auto &platform : platforms) {
      DrawRectangleRec(platform, BLUE);
    }
  }

  std::vector<Rectangle> getPlatforms() override { return platforms; }

  void update() override {
    // Update logic specific to LevelTen
  }
};

#endif // LEVELTEN_H
