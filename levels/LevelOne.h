#include "vector"
#include <raylib.h>
#include "elements/platforms/Wall.h"
#include "elements/platforms/Floor.h"
class LevelOne {
private:
  int stageCount = 1;
  std::vector<Rectangle> platforms;

public:
  void drawPlatforms() {
    Floor p1(300, 400, 1.0, 300, 10, true);
    platforms.push_back({300, 400, 300, 10});
    Floor p2(200, 500, 1.0, 200, 10, true);
    platforms.push_back({200, 500, 200, 10});
    Floor p3(300, 600, 1.0, 400, 10, true);
    platforms.push_back({300, 600, 400, 10});
    Wall p4(300, 300, 1.0, 10, 600, true);
    platforms.push_back({300, 300, 10, 600});
    Wall p5(800, 300, 1.0, 10, 600, true);
    platforms.push_back({800, 300, 10, 600});




  }
  std::vector<Rectangle> getPlatforms() { return platforms; }
};
