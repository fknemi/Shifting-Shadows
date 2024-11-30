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
    }
};

class LevelOne {
private:
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
