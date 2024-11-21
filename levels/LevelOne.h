<<<<<<< HEAD
<<<<<<< HEAD
#ifndef LEVELONE_H
#define LEVELONE_H

#include <raylib.h>
#include <vector>

class Obstacle {
public:
    Vector2 position;
    Texture2D texture;

    Obstacle(Vector2 pos, const char* texturePath) {
        position = pos;
        texture = LoadTexture(texturePath);
    }

    ~Obstacle() {
        UnloadTexture(texture);
    }

    void draw() {
        DrawTexture(texture, position.x, position.y, WHITE);
=======
=======
#include "vector"
>>>>>>> 9fe5fc9 (fixed player falling through floor when reset && updated LevelOne to use vector for platforms)
#include <raylib.h>
struct Platform {
  float x;
  float y;
  float opacity;
  float width;
  float height;
  bool enabledCollision;
  bool isVisibleToPlayer;
  bool drawPlatform;

  // Constructor to initialize the struct
  Platform(int x, int y, float opacity, float width, float height,
           bool enabledCollision)
      : x(x), y(y), opacity(opacity), width(width), height(height),
        enabledCollision(enabledCollision), isVisibleToPlayer(true),
        drawPlatform(true) {
    if (drawPlatform) {
      draw();
    }
  }

  // Draw function to draw the platform
  void draw() { DrawRectangle(x, y, width, height, GREEN); }

<<<<<<< HEAD
    // Function to get the platform's rectangle
    Rectangle getPlatform() {
        return platform;
>>>>>>> 82ba856 (added floor platform with collision and collision methods to Player)
    }
=======
  // Function to get the platform's rectangle
>>>>>>> 9fe5fc9 (fixed player falling through floor when reset && updated LevelOne to use vector for platforms)
};

class LevelOne {
private:
<<<<<<< HEAD
<<<<<<< HEAD
    std::vector<Obstacle> obstacles;

public:
    LevelOne() {
        // Add obstacles
        obstacles.push_back(Obstacle({300, 600}, "resources/tree.png")); // Tree
        obstacles.push_back(Obstacle({500, 650}, "resources/animal.png")); // Animal
        obstacles.push_back(Obstacle({800, 700}, "resources/bomb.png")); // Bomb
    }

    void draw() {
        for (auto& obstacle : obstacles) {
            obstacle.draw();
        }
    }

    const std::vector<Obstacle>& getObstacles() const {
        return obstacles;
    }
};

#endif
=======
    int stageCount = 1;
    Platform platforms[1];
=======
  int stageCount = 1;
  std::vector<Rectangle> platforms;
>>>>>>> 9fe5fc9 (fixed player falling through floor when reset && updated LevelOne to use vector for platforms)

public:
  LevelOne() { Platform(300, 600, 1.0, 600, 10, true); }
  void drawPlatforms() {
    Platform p1(300, 600, 1.0, 600, 10, true);
    Platform p2(300, 300, 1.0, 10, 600, true);
    platforms.push_back({300, 300, 10, 600});
    platforms.push_back({300, 600, 600, 10});

  }
  std::vector<Rectangle> getPlatforms() { return platforms; }
};
>>>>>>> 82ba856 (added floor platform with collision and collision methods to Player)
