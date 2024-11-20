#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
class Player {
public:
    Player(float screenWidth, float screenHeight, float x, float y, int vel = 2);
    void draw();
    void moveLeft();
    void moveRight();
    void jump();
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
};

#endif // PLAYER_H
