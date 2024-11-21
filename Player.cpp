#include "Player.h"
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

