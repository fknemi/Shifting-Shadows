#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player(int screenWidth, int screenHeight, int x = 0, int y = 0, int vel = 2);
    void draw();
    void moveLeft();
    void moveRight();
    void jump();
    void update(float deltaTime);

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
    static constexpr float gravity = 700.0f;
    static constexpr float jumpSpeed = 350.0f;
};

#endif // PLAYER_H
