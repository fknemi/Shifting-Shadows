#include "Player.h"
#include <cstdio>
#include <raylib.h>

Player::Player(int screenWidth, int screenHeight, float x, float y, int vel)
    : screenWidth(screenWidth), screenHeight(screenHeight), x(x), y(y), vel(vel), speed(0), canJump(false) {}

void Player::draw() { DrawRectangle(x, y, 60, 60, RED); }

void Player::moveLeft() { x -= vel; }

void Player::moveRight() { x += vel; }

void Player::jump() {
  if (canJump) {
    speed = -jumpSpeed;
    canJump = false;
  }
}

void Player::update(float deltaTime) {
  y += speed * deltaTime;
  speed += gravity * deltaTime;
  if (didHitObstacle) {
    speed = 0;
  }
}

void Player::reset() {
  y = (float)screenHeight / 4;
  x = (float)screenWidth / 2;
  speed = 0;
}
void Player::resetCollisions() {
  didHitObstacle = false;
  if(speed == 0){

  canJump = true;
  }
}
void Player::checkCollisions(bool xAxis, bool yAxis, Rectangle platform) {
  if (yAxis) {

    didHitObstacle = true;
    if (y + 60 >= platform.y - 70) {
    speed = 0;
      y = platform.y - 60;
    }
  } else {
    didHitObstacle = false;
  }
}

Rectangle Player::getPosition() { return {x, y, 60, 60}; }

float Player::GetRectBottom(Rectangle rect) { return rect.y + rect.height; }
