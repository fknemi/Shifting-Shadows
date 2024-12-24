#ifndef PLAYER_H
#define PLAYER_H

#include <array>
#include <raylib.h>
class Player {
private:
    Vector2 position;       // Player's position
    Vector2 velocity;       // Player's velocity
    int screenWidth;        // Screen width for boundaries
    int screenHeight;       // Screen height for boundaries
    float jumpForce;        // Force applied when jumping
    int jumpCount;          // Track the number of jumps
    Texture2D texture;      // Player sprite

public:
  Player(int screenWidth, int screenHeight, float x, float y, int vel = 2);
  void draw();
  void moveLeft();
  void moveRight();
  void jump();
  void reset();
  void update(float deltaTime);
  void checkCollisions(bool x, bool y, Rectangle platform, float deltatime);
  Rectangle getPosition();
  float GetRectBottom(Rectangle rect);

private:
  float x;
  float y;
  int width = 60;
  int height = 60;
  int vel;
  bool hitFloor = false;
  bool hitLeftWall = false;
  bool hitRightWall = false;
  int hearts = 5;
  float tongueDelay;
  float tongueReachLimit;
  float speed;
  bool canJump;
  bool isOnGround;
  std::array<int, 3> yAxisCollisionoffsets = {10, 20, 35};
  int xAxisCollisionoffset = 5;
  
  static constexpr float gravity = 0;
  static constexpr float jumpSpeed = 500.0f;
};

#endif
