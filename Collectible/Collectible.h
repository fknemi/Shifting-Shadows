#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

#include <raylib.h>

struct Collectible {
    Vector2 position;
    bool isCoin;  // true for coin, false for fruit

    void draw() {
        DrawCircle(position.x, position.y, 10, isCoin ? GOLD : GREEN);
    }
};

#endif // COLLECTIBLE_H
