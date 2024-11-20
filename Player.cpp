#include "Player.h"
<<<<<<< HEAD
#include <raylib.h>

Player::Player(int screenWidth, int screenHeight, float x, float y, const char* texturePath)
    : screenWidth(screenWidth), screenHeight(screenHeight), gravity(300.0f), jumpForce(-400.0f) {
    position = {x, y};
    velocity = {0, 0};

    // Load the player texture
    texture = LoadTexture(texturePath);
}

Player::~Player() {
    // Unload the player texture when the object is destroyed
    UnloadTexture(texture);
}

void Player::update(float deltaTime) {
    // Apply gravity
    velocity.y += gravity * deltaTime;
    position.y += velocity.y * deltaTime;

    // Prevent falling through the floor
    if (position.y > screenHeight - texture.height) { // Adjust based on texture height
        position.y = screenHeight - texture.height;
        velocity.y = 0;
        jumpCount = 0;  //Reset Jump Count
    }
}

void Player::draw() {
    DrawTexture(texture, position.x, position.y, WHITE); // Draw the player sprite
}

void Player::moveLeft() {
    position.x -= 200 * GetFrameTime(); // Move left
}

void Player::moveRight() {
    position.x += 200 * GetFrameTime(); // Move right
}

void Player::jump() {
    if (position.y >= screenHeight - texture.height) { // Only jump if on the ground
        velocity.y = jumpForce;
    }
=======
#include <cstdio>
#include <raylib.h>

Player::Player(float screenWidth, float screenHeight, float x, float y, int vel)
    : x(x), y(y), vel(vel), speed(0), canJump(false) {}

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
>>>>>>> 82ba856 (added floor platform with collision and collision methods to Player)
}

void Player::reset() {
  y = 800 / 4;
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

Rectangle Player::getPosition() { return {(float)x, (float)y, 60, 60}; }

float Player::GetRectBottom(Rectangle rect) { return rect.y + rect.height; }
