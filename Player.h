#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

class Player {
private:
    Vector2 position;       // Player's position
    Vector2 velocity;       // Player's velocity
    int screenWidth;        // Screen width for boundaries
    int screenHeight;       // Screen height for boundaries
    float gravity;          // Gravity affecting the player
    float jumpForce;        // Force applied when jumping
    int jumpCount;          // Track the number of jumps
    Texture2D texture;      // Player sprite

public:
    Player(int screenWidth, int screenHeight, float x, float y, const char* texturePath);
    ~Player();
    void update(float deltaTime);
    void draw();
    void moveLeft();
    void moveRight();
    void jump();
};

#endif
