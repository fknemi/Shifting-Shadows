#include "Level.h"
#include "vector"
#include <raylib.h>

#ifndef LEVELFOUR_H
#define LEVELFOUR_H

#include "Level.h" // Make sure you're including the base class header

class LevelFour : public Level {
private:
  int stageCount = 1;
  std::vector<Rectangle> platforms;

public:
  LevelFour() {
    platforms.push_back({100, 200, 200, 10}); // Example platform
  }

  void drawPlatforms() override {
    for (const auto &platform : platforms) {
      DrawRectangleRec(platform, BLUE);
    }
  }

  std::vector<Rectangle> getPlatforms() override { return platforms; }

  void update() override {
    // Update logic specific to LevelFour
  }
};

#endif // LEVELFOUR_H
