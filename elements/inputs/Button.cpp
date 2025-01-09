#include "Button.h"
#include <raylib.h>
#include <iostream>

Button::Button(const char *imagePath, Vector2 imagePosition, float scale) {
  std::cout << "Loading image from path: " << imagePath << std::endl;
  Image image = LoadImage(imagePath);
  if (image.data == nullptr) {
    std::cerr << "Failed to load image: " << imagePath << std::endl;
    return;
  }
  int originalWidth = image.width;
  int originalHeight = image.height;
  int newWidth = static_cast<int>(originalWidth * scale);
  int newHeight = static_cast<int>(originalHeight * scale);

  ImageResize(&image, newWidth, newHeight);
  texture = LoadTextureFromImage(image);
  UnloadImage(image);
  position = imagePosition;
  std::cout << "Image loaded and texture created successfully: " << imagePath << std::endl;
}

Button::~Button() {
  if (texture.id != 0) {
    UnloadTexture(texture);
  }
}

void Button::draw() {
  DrawTextureV(texture, position, WHITE);
  Rectangle rect = {position.x, position.y, static_cast<float>(texture.width),
                    static_cast<float>(texture.height)};
 // DrawRectangleLines(rect.x, rect.y, rect.width, rect.height, RED); // Visualize the button's collision area
}

bool Button::isPressed(Vector2 mousePos, bool mousePressed) {
  Rectangle rect = {position.x, position.y, static_cast<float>(texture.width),
                    static_cast<float>(texture.height)};
  return CheckCollisionPointRec(mousePos, rect) && mousePressed;
}
