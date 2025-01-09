#ifndef BUTTON_H
#define BUTTON_H

#include <raylib.h>

class Button {
public:
  Button(const char *imagePath, Vector2 imagePosition, float scale);
  ~Button();
  void draw();
  bool isPressed(Vector2 mousePos, bool mousePressed);

private:
  Texture texture;
  Vector2 position;
};

#endif
