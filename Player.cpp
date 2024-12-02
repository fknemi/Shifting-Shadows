#include "Player.h"
<<<<<<< HEAD
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
=======
>>>>>>> d750e8c (fixed floor and wall collisions, 1 issue left)
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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  y += speed * deltaTime;
  speed += gravity * deltaTime;
  if (didHitObstacle) {
    speed = 0;
  }
>>>>>>> 82ba856 (added floor platform with collision and collision methods to Player)
=======
    y += speed * deltaTime;  // Apply vertical movement based on speed
    speed += gravity * deltaTime;  // Apply gravity (falling speed increases)
    
    DrawText("x", 1280*0.4, 300, 20, RED);
    DrawText(std::to_string(x).c_str(), 1280*0.45, 300, 20, RED);
    DrawText("y", 1280*0.6, 300, 20, RED);
    DrawText(std::to_string(y).c_str(), 1280*0.65, 300, 20, RED);
    if (hitFloor) {
        speed = 0;  
        canJump = true;  
        hitFloor = false;
    }
    if(hitRightWall){
        hitRightWall = false;
    }
    if(hitLeftWall){
        hitLeftWall = true;
    }
>>>>>>> 9fe5fc9 (fixed player falling through floor when reset && updated LevelOne to use vector for platforms)
=======
  y += speed * deltaTime;
=======
  pos.y += speed * deltaTime;
>>>>>>> 57b11f3 (seperated platforms to Wall.h and Floor.h, used vector2 for player position, removed deltatime from checkCollisions for Player)
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
>>>>>>> d750e8c (fixed floor and wall collisions, 1 issue left)
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
