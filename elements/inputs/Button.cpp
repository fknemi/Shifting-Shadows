#include "Button.h"
#include <raylib.h>

Button::Button(const char *imagePath, Vector2 imagePosition, float scale) {
  Image image = LoadImage(imagePath);
  int originalWidth = image.width;
  int originalHeight = image.height;
  int newWidth = static_cast<int>(originalWidth * scale);
  int newHeight = static_cast<int>(originalHeight * scale);

  ImageResize(&image, newWidth, newHeight);
  texture = LoadTextureFromImage(image);
  UnloadImage(image);
  position = imagePosition;
}

Button::~Button() { UnloadTexture(texture); }

void Button::draw() {

  DrawTextureV(texture, position, WHITE);
  Rectangle rect = {position.x, position.y, static_cast<float>(texture.width),
                    static_cast<float>(texture.height)};
  DrawRectangleLines(rect.x, rect.y, rect.width, rect.height,
                     RED); // Visualize the button's collision area
}

bool Button::isPressed(Vector2 mousePos, bool mousePressed) {

  Rectangle rect = {position.x, position.y, static_cast<float>(texture.width),


      static_cast<float>(texture.height)};


    if (CheckCollisionPointRec(mousePos, rect) && mousePressed) {
        return true;
    }
    return false;
}
