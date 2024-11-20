#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
<<<<<<< HEAD

=======
>>>>>>> 82ba856 (added floor platform with collision and collision methods to Player)
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
<<<<<<< HEAD
    Player(int screenWidth, int screenHeight, float x, float y, const char* texturePath);
    ~Player();
    void update(float deltaTime);
=======
    Player(float screenWidth, float screenHeight, float x, float y, int vel = 2);
>>>>>>> 82ba856 (added floor platform with collision and collision methods to Player)
    void draw();
    void moveLeft();
    void moveRight();
    void jump();
<<<<<<< HEAD
=======
    void reset();
    void resetCollisions();
    void update(float deltaTime);
    void checkCollisions(bool x, bool y, Rectangle platform);
    Rectangle getPosition();
    float GetRectBottom(Rectangle rect);

private:
    int x;
    int y;
    int vel;
    bool didHitObstacle = false;
    int hearts = 5;
    float tongueDelay;
    float tongueReachLimit;
    float speed;
    bool canJump;
    float yCollisionAxis;
    static constexpr float gravity = 700.0f;
    static constexpr float jumpSpeed = 350.0f;
>>>>>>> 82ba856 (added floor platform with collision and collision methods to Player)
};

#endif
