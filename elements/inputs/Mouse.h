#ifndef MOUSE_H
#define MOUSE_H

#include <raylib.h>

class Mouse {
public:
    Mouse(); // Constructor
    void update(); // Update the mouse position
    void draw();   // Draw a circle at the mouse position
private:
    Vector2 position; // Stores the current mouse position
};

#endif // MOUSE_H