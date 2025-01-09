#ifndef LEVEL_H
#define LEVEL_H
#include <raylib.h>
#include "../elements/platforms/Platform.h"
#include "../elements/platforms/Object.h"
#include "vector"


#include <raylib.h>
#include <vector>

class Level {

public:
  virtual ~Level() {
  } 

  virtual void drawPlatforms() = 0;
  virtual void drawObjects() = 0;

  virtual std::vector<Rectangle> getPlatforms() = 0;

  virtual void update() = 0; 
};

#endif // LEVEL_H
