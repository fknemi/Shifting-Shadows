<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#ifndef LEVELONE_H
#define LEVELONE_H

#include <raylib.h>
<<<<<<< HEAD
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
<<<<<<< HEAD
=======
>>>>>>> 9ecd4bc (added basic start menu, added onGround to Player (not used))
struct Platform {
  float x;
  float y;
  float opacity;
  float width;
  float height;
  bool enabledCollision;
  bool isVisibleToPlayer;
  bool drawPlatform;
=======
#include "Level.h"
#include "../elements/platforms/Platform.h"
#include "vector"
#include <raylib.h>
<<<<<<< HEAD
>>>>>>> b847e32 (added files for all levels and removed broken texture causing seg fault)

=======
#include <iostream>
>>>>>>> 90b2781 (pretty it up later 1)
#ifndef LEVELONE_H
#define LEVELONE_H

#include "Level.h" // Make sure you're including the base class header

<<<<<<< HEAD
<<<<<<< HEAD
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

=======
#include "../elements/platforms/Wall.h"
#include "../elements/platforms/Floor.h"
>>>>>>> 57b11f3 (seperated platforms to Wall.h and Floor.h, used vector2 for player position, removed deltatime from checkCollisions for Player)
=======
  // Function to get the platform's rectangle
};

>>>>>>> 9ecd4bc (added basic start menu, added onGround to Player (not used))
class LevelOne {
=======
class LevelOne : public Level {
<<<<<<< HEAD
>>>>>>> b847e32 (added files for all levels and removed broken texture causing seg fault)
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
=======
    private:
        int stageCount = 1;
        std::vector<Rectangle> platforms;
        Platform *platformBottom = new Platform("assets/LevelOne/platform.png", {0,800}, 1);
>>>>>>> 90b2781 (pretty it up later 1)

    public:
        LevelOne() {
            platformBottom->draw();
            Rectangle p1 = platformBottom->getSize();
            platforms.push_back({p1.x,p1.height - 62,p1.width,p1.height - 98}); // x,y,w,h
            platforms.push_back({530,p1.height- 110,p1.width - 530,p1.height - 400}); // x,y,w,h
            platforms.push_back({625,p1.height- 158,p1.width - 625,p1.height - 400}); // x,y,w,h

        }

        void drawPlatforms() override {
            for (const auto &platform : platforms) {
                DrawRectangleLines(platform.x, platform.y, platform.width, platform.height, RED); // Visualize the platform's collision area

            }
        }

        std::vector<Rectangle> getPlatforms() override { return platforms; }

        void update() override {
            // Update logic specific to LevelOne
        }
};
<<<<<<< HEAD
>>>>>>> 82ba856 (added floor platform with collision and collision methods to Player)
=======

#endif // LEVELONE_H
>>>>>>> b847e32 (added files for all levels and removed broken texture causing seg fault)
