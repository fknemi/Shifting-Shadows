#include "Level.h"
#include "vector"
#include <raylib.h>

#ifndef LEVELNINE_H
#define LEVELNINE_H

#include "Level.h" // Make sure you're including the base class header

class LevelNine : public Level {
private:
  int stageCount = 9;
  std::vector<Rectangle> platforms;

public:
  LevelNine() {
    platforms.push_back({100, 200, 200, 10}); // Example platform
  }

  void drawPlatforms() override {
    for (const auto &platform : platforms) {
      DrawRectangleRec(platform, BLUE);
    }
  }
     void drawObjects() override {
        }

  std::vector<Rectangle> getPlatforms() override { return platforms; }

  void update() override {
    // Update logic specific to LevelOne
  }
};

#endif // LEVELNINE_H
