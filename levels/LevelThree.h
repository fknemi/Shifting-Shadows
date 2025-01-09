#include "Level.h"
#include "vector"
#include <raylib.h>

#ifndef LEVELTHREE_H
#define LEVELTHREE_H

#include "Level.h" // Make sure you're including the base class header

class LevelThree : public Level {
private:
  int stageCount = 3;
  std::vector<Rectangle> platforms;

public:
  LevelThree() {
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
    // Update logic specific to LevelThree
  }
};

#endif // LEVELTHREE_H
