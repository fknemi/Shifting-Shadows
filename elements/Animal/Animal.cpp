#include "Animal.h"
#include <raylib.h>

// Constructor to initialize the animal's position and sprite
Animal::Animal(Vector2 position) : position(position) {
    sprite = LoadTexture("resources/animal.png");  // Load the animal's sprite
}

// Destructor to unload the sprite when the object is destroyed
Animal::~Animal() {
    UnloadTexture(sprite);  // Unload the animal's sprite
}

// Method to draw the animal at its current position
void Animal::draw() {
    DrawTexture(sprite, position.x, position.y, WHITE); // Draw the animal's sprite
}

// Method to move the animal
void Animal::move(float deltaTime) {
    // Simple movement logic: move the animal to the right
    position.x += 100 * deltaTime; // Move right at a constant speed

    // Loop the animal back to the left side of the screen after it goes off the right
    if (position.x > GetScreenWidth()) {
        position.x = -sprite.width; // Move to the left side of the screen
    }
}

// Method to get the current position of the animal
Vector2 Animal::getPosition() {
    return position;
}
