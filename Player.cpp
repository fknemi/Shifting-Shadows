#include "Player.h"
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
}
