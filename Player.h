#ifndef PLAYER_H
#define PLAYER_H

#include <array>
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
    float jumpForce;        // Force applied when jumping
    int jumpCount;          // Track the number of jumps
    Texture2D texture;      // Player sprite

public:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    Player(int screenWidth, int screenHeight, float x, float y, const char* texturePath);
    ~Player();
    void update(float deltaTime);
=======
    Player(float screenWidth, float screenHeight, float x, float y, int vel = 2);
>>>>>>> 82ba856 (added floor platform with collision and collision methods to Player)
=======
    Player(int screenWidth, int screenHeight, float x, float y, int vel = 2);
>>>>>>> aabba52 (updated Keybinds for player and added todo in Config.cpp, fixed collision for floor platform)
    void draw();
    void moveLeft();
    void moveRight();
    void jump();
<<<<<<< HEAD
=======
    void reset();
    void update(float deltaTime);
    void checkCollisions(bool x, bool y, Rectangle platform);
    Rectangle getPosition();
    float GetRectBottom(Rectangle rect);
=======
  Player(int screenWidth, int screenHeight, float x, float y, int vel = 2);
  void draw();
  void moveLeft();
  void moveRight();
  void jump();
  void reset();
  void update(float deltaTime);
  void checkCollisions(bool x, bool y, Rectangle platform, float deltatime);
  Rectangle getPosition();
  float GetRectBottom(Rectangle rect);
>>>>>>> d750e8c (fixed floor and wall collisions, 1 issue left)

private:
  float x;
  float y;
  int width = 60;
  int height = 60;
  int vel;
  bool hitFloor = false;
  bool hitLeftWall = false;
  bool hitRightWall = false;
  int hearts = 5;
  float tongueDelay;
  float tongueReachLimit;
  float speed;
  bool canJump;
  bool isOnGround;
  std::array<int, 3> yAxisCollisionoffsets = {10, 20, 35};
  int xAxisCollisionoffset = 5;
<<<<<<< HEAD

<<<<<<< HEAD
    static constexpr float gravity = 700.0f;
    static constexpr float jumpSpeed = 350.0f;
>>>>>>> 82ba856 (added floor platform with collision and collision methods to Player)
=======
=======
  
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 517c71c (2D camera update)
  static constexpr float gravity = 700.0f;
=======
  static constexpr float gravity = 0;
>>>>>>> dc95e91 (idk too much)
=======
  static constexpr float gravity = 300.00f;
>>>>>>> 90b2781 (pretty it up later 1)
  static constexpr float jumpSpeed = 500.0f;
>>>>>>> d750e8c (fixed floor and wall collisions, 1 issue left)
};

#endif
