#include "Player.h"
#include <raylib.h>
#include <string>
Player::Player(int screenWidth, int screenHeight, float x, float y, int vel)
    : screenWidth(screenWidth), screenHeight(screenHeight),
      vel(vel), speed(0), canJump(false), hitFloor(false) {
          pos.x = x;
          pos.y = y;
      }

void Player::draw() { DrawRectangle(pos.x, pos.y, 60, 60, RED); }

void Player::moveLeft() {
  if (!hitLeftWall) {
    pos.x -= vel;

  }
}

void Player::moveRight() {
  if (!hitRightWall) {
    pos.x += vel;
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
  pos.y += speed * deltaTime;
  speed += gravity * deltaTime;

  DrawText("x", 1280 * 0.7, 50, 20, RED);
  DrawText(std::to_string(pos.x).c_str(), 1280 * 0.72, 50, 20, RED);
  DrawText("y", 1280 * 0.7, 100, 20, RED);
  DrawText(std::to_string(pos.y).c_str(), 1280 * 0.72, 100, 20, RED);
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
  pos.y = (float)screenHeight / 4;
  pos.x = (float)screenWidth / 2;
  speed = 0;
  hitFloor = false;
  hitLeftWall = false;
  hitRightWall = false;
}


// TODO: Fix Sometimes Player Can Jump While Falling
void Player::checkCollisions(bool xAxis, bool yAxis, Rectangle platform) {
  // Vertical collision (y-axis)
  if (yAxis) {
    if (pos.y + height > platform.y && pos.y + height <= platform.y + 10 &&
        pos.x + width > platform.x && pos.x < platform.x + platform.width &&
        speed > 0) {
      pos.y = platform.y - height;
      speed = 0;
      hitFloor = true;
    } else if (pos.y - yAxisCollisionoffsets[1] < platform.y + platform.height &&
               pos.y + height - yAxisCollisionoffsets[2] > platform.y + platform.height &&
               pos.x + width - yAxisCollisionoffsets[2] > platform.x && pos.x < platform.x + platform.width &&
               speed < 0) {
      pos.y = platform.y + platform.height;
      speed = 0;
    } else {
      hitFloor = false;
    }
  }

  // Horizontal collision (x-axis)
  if (xAxis) {
    if (pos.x + width + xAxisCollisionoffset > platform.x &&
        pos.x - xAxisCollisionoffset < platform.x && 
        pos.y + height > platform.y && pos.y < platform.y + platform.height) {
      pos.x = platform.x - width;
      hitLeftWall = true;
    } else if (pos.x < platform.x + platform.width &&
               pos.x + width >
                   platform.x + platform.width && 
               pos.y + height > platform.y &&
               pos.y < platform.y + platform.height) {
      pos.x = platform.x + platform.width;
      hitRightWall = true;
    } else {
      hitLeftWall = false;
      hitRightWall = false;
    }
  }
}

Rectangle Player::getPosition() { return {pos.x, pos.y, width, height}; }

float Player::GetRectBottom(Rectangle rect) { return rect.y + rect.height; }
