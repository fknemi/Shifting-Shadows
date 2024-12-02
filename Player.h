#ifndef PLAYER_H
#define PLAYER_H

#include <array>
#include <raylib.h>
class Player {
public:
  Player(int screenWidth, int screenHeight, float x, float y, int vel = 2);
  void draw();
  void moveLeft();
  void moveRight();
  void jump();
  void reset();
  void update(float deltaTime);
  void checkCollisions(bool x, bool y, Rectangle platform);
  Rectangle getPosition();
  float GetRectBottom(Rectangle rect);

private:
  Vector2 pos;
  int screenWidth;
  int screenHeight;
  float width = 60;
  float height = 60;
  int vel;
  bool hitFloor = false;
  bool hitLeftWall = false;
  bool hitRightWall = false;
  float tongueDelay;
  float tongueReachLimit;
  float speed;
  bool canJump;
  std::array<int, 3> yAxisCollisionoffsets = {10, 20, 35};
  int xAxisCollisionoffset = 5;

  static constexpr float gravity = 700.0f;
  static constexpr float jumpSpeed = 500.0f;
};

#endif // PLAYER_H
