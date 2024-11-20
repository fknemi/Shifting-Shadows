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
    Rectangle platform;

    // Constructor to initialize the struct
    Platform(int x, int y, float opacity, float width, float height, bool enabledCollision)
        : x(x), y(y), opacity(opacity), width(width), height(height), enabledCollision(enabledCollision),
          isVisibleToPlayer(true), drawPlatform(true) {
        if (drawPlatform) {
            draw();
        }
    }

    // Draw function to draw the platform
    void draw() {
        DrawRectangle(x, y, width, height, GREEN);
        platform = { x, y, width, height };
    }

    // Function to get the platform's rectangle
    Rectangle getPlatform() {
        return platform;
    }
};

class LevelOne {
private:
    int stageCount = 1;
    Platform platforms[1];

public:
    LevelOne() : platforms{ Platform(300, 600, 1.0, 600, 10, true) } {}
    void drawPlatforms() {
        Platform p1(300, 600, 1.0, 600, 10, true);
        platforms[0] = p1;
    }

    Rectangle getPlatforms() {
        return platforms[0].getPlatform();
    }
};
