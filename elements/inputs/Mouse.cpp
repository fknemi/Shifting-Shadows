// Class Mouse
// Call Update In The Game Loop To Constantly Update The Current Mouse X,Y On
// The Screen, Draw A Custom Circle Or Overlay For The Mouse
#include "Mouse.h"

void Mouse::update() {
  // Update the mouse position based on its current location
  position = GetMousePosition();
  //HideCursor();
}

void Mouse::draw() {
  // Draw a circle at the current mouse position
  DrawCircleV(position, 10, RAYWHITE);
}

