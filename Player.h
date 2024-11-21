#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
class Player {
public:
    Player(int screenWidth, int screenHeight, float x, float y, int vel = 2);
    void draw();
    void moveLeft();
    void moveRight();
    void jump();
    void reset();
    void update(float deltaTime);
    void checkCollisions(bool x, bool y, Rectangle platform);
    Rectangle getPosition();
    float GetRectBottom(Rectangle rect);

private:
    float x;
    float y;
    int screenWidth;
    int screenHeight;
    int vel;
    bool hitFloor = false;
    bool hitLeftWall = false;
    bool hitRightWall = false;
    int hearts = 5;
    float tongueDelay;
    float tongueReachLimit;
    float speed;
    bool canJump;
    float yCollisionAxis;

    static constexpr float gravity = 700.0f;
    static constexpr float jumpSpeed = 350.0f;
};

#endif // PLAYER_H
