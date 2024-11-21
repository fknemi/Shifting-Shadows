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
#include <string>
Player::Player(int screenWidth, int screenHeight, float x, float y, int vel)
    : screenWidth(screenWidth), screenHeight(screenHeight), x(x), y(y),
      vel(vel), speed(0), canJump(false), hitFloor(false) {}

void Player::draw() { 
    DrawRectangle(x, y, 60, 60, RED); 
}

void Player::moveLeft() { 
    if(!hitLeftWall){
    x -= vel;
    }
}

void Player::moveRight() { 
    if(!hitRightWall){
    x += vel; 
    }
}

void Player::jump() {
    if (canJump) {
        speed = -jumpSpeed;  // Set the initial jump speed
        canJump = false;     // Disable further jumps until grounded
        hitFloor = false;
    }
}

void Player::update(float deltaTime) {
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
}

void Player::reset() {
    y = (float)screenHeight / 4;
    x = (float)screenWidth / 2; 
    speed = 0;
    hitFloor = false;
    hitLeftWall = false;
    hitRightWall = false;
}

void Player::checkCollisions(bool xAxis, bool yAxis, Rectangle platform) {
    // Handle Collision With Floor
    if (yAxis) {
        if (platform.width > platform.height && y + 60 >= platform.y && y + 60 <= platform.y + platform.height && speed >= 0) { 
            y = platform.y - 60;  
            speed = 0;
            hitFloor = true; 
        }
    } else {
        hitFloor = false;
    }
if (xAxis) {
    // TODO: Fix Wall Collision
        if (platform.height > platform.width && x < platform.x) {
            hitLeftWall = true;
            hitRightWall = false; 
        }
        else if (platform.height > platform.width && x + 60 >= platform.x + platform.width) {
            hitRightWall = true;
            hitLeftWall = false; // Make sure to reset the left wall hit flag
        } else {
            hitLeftWall = false;
            hitRightWall = false;
        }
    }
}

Rectangle Player::getPosition() { 
    return {x, y, 60, 60};  
}

float Player::GetRectBottom(Rectangle rect) { 
    return rect.y + rect.height; 
}

