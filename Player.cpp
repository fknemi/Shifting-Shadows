#include "Player.h"
#include <raylib.h>
#include <cstdio>

Player::Player(int screenWidth, int screenHeight, int x, int y, int vel)
    : x(x), y(y), vel(vel), speed(0), canJump(false) {
}

void Player::draw() {
    DrawRectangle(x, y, 60, 60, RED);
}

void Player::moveLeft() {
    x -= vel;
}

void Player::moveRight() {
    x += vel;
}

void Player::jump() {
    if (canJump) {
        speed = -jumpSpeed;
        canJump = false;
    }
}

void Player::update(float deltaTime) {
    // Apply gravity
    y += speed * deltaTime;
    speed += gravity * deltaTime;

    // Check if player is on the ground
    if (y >= 600) { // Assuming the ground is at y = 600
        y = 600;
        speed = 0;
        canJump = true;
    }
}
