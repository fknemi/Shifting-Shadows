#ifndef ANIMAL_H
#define ANIMAL_H

#include <raylib.h>

// Animal class to represent the animals in the game
class Animal {
private:
    Vector2 position;   // Position of the animal on the screen
    Texture2D sprite;   // Sprite for the animal (e.g., an image of the animal)
    
public:
    // Constructor to initialize the animal's position and sprite
    Animal(Vector2 position);

    // Destructor to unload the sprite when the object is destroyed
    ~Animal();

    // Method to draw the animal at its current position
    void draw();

    // Method to move the animal
    void move(float deltaTime);

    // Method to get the current position of the animal
    Vector2 getPosition();
};

#endif // ANIMAL_H
