#ifndef LEVEL_H
#define LEVEL_H

#include <raylib.h>
#include <vector>

class Level {
public:
  virtual ~Level() {
  } // Virtual destructor to ensure proper cleanup for derived classes

  // Virtual functions that can be overridden by each specific level
  virtual void drawPlatforms() = 0;
  virtual std::vector<Rectangle> getPlatforms() = 0;

  // Other shared functions (if any) could go here, for example:
  virtual void update() = 0; // If you want each level to have an update logic
};

#endif // LEVEL_H
