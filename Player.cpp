#include "Player.h"
#include <raylib.h>
#include <string>
Player::Player(int screenWidth, int screenHeight, float x, float y, int vel)
    : screenWidth(screenWidth), screenHeight(screenHeight), x(x), y(y),
      vel(vel), speed(0), canJump(false), hitFloor(false) {}

void Player::draw() { DrawRectangle(x, y, 60, 60, RED); }

void Player::moveLeft() {
  if (!hitLeftWall) {
    x -= vel;
  }
}

void Player::moveRight() {
  if (!hitRightWall) {
    x += vel;
  }
}

void Player::jump() {
  if (canJump) {
    speed = -jumpSpeed;
    canJump = false;
    hitFloor = false;
  }
}

void Player::update(float deltaTime) {
  y += speed * deltaTime;
  speed += gravity * deltaTime;

  DrawText("x", 1280 * 0.7, 50, 20, RED);
  DrawText(std::to_string(x).c_str(), 1280 * 0.72, 50, 20, RED);
  DrawText("y", 1280 * 0.7, 100, 20, RED);
  DrawText(std::to_string(y).c_str(), 1280 * 0.72, 100, 20, RED);
  if (hitFloor) {
    speed = 0;
    canJump = true;
    hitFloor = false;
  }
  if (hitRightWall) {
    hitRightWall = false;
  }
  if (hitLeftWall) {
    hitLeftWall = false;
  }
}

void Player::reset() {
  y = (float)screenHeight / 4;
  x = (float)screenWidth / 2;
  speed = 0;
  hitFloor = false;
  hitLeftWall = false;
  hitRightWall = false;
}


// TODO: Fix Sometimes Player Can Jump While Falling
void Player::checkCollisions(bool xAxis, bool yAxis, Rectangle platform,
                             float deltatime) {
  // Vertical collision (y-axis)
  if (yAxis) {
    if (y + height > platform.y && y + height <= platform.y + 10 &&
        x + width > platform.x && x < platform.x + platform.width &&
        speed > 0) {
      y = platform.y - height;
      speed = 0;
      hitFloor = true;
    } else if (y - yAxisCollisionoffsets[1] < platform.y + platform.height &&
               y + height - yAxisCollisionoffsets[2] > platform.y + platform.height &&
               x + width - yAxisCollisionoffsets[2] > platform.x && x < platform.x + platform.width &&
               speed < 0) {
      y = platform.y + platform.height;
      speed = 0;
    } else {
      hitFloor = false;
    }
  }

  // Horizontal collision (x-axis)
  if (xAxis) {
    if (x + width + xAxisCollisionoffset > platform.x &&
        x - xAxisCollisionoffset < platform.x && 
        y + height > platform.y && y < platform.y + platform.height) {
      x = platform.x - width;
      hitLeftWall = true;
    } else if (x < platform.x + platform.width &&
               x + width >
                   platform.x + platform.width && 
               y + height > platform.y &&
               y < platform.y + platform.height) {
      x = platform.x + platform.width;
      hitRightWall = true;
    } else {
      hitLeftWall = false;
      hitRightWall = false;
    }
  }
}

Rectangle Player::getPosition() { return {x, y, 60, 60}; }

float Player::GetRectBottom(Rectangle rect) { return rect.y + rect.height; }
