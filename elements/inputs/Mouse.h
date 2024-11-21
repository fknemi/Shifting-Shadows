#ifndef MOUSE_H
#define MOUSE_H

#include <raylib.h>

class Mouse {
public:
    void update(); // Update the mouse position
    void draw();   // Draw a circle at the mouse position
private:
    Vector2 position = { 0, 0 }; // Stores the current mouse position
    // Hide the system mouse
};

#endif // MOUSE_H