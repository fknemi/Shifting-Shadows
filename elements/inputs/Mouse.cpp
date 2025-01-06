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

