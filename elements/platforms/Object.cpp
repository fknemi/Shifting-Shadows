#include "Object.h"
#include <raylib.h>


Object::Object(const char *imagePath, Vector2 imagePosition, float scale){
    texture = LoadTexture(imagePath);
    position = imagePosition;
}

void Object::enableCollision(){

}

Object::~Object(){
    UnloadTexture(texture);
}

void Object::draw(){
    DrawTexture(texture, position.x, position.y - texture.height, WHITE);
}
Rectangle Object::getSize(){
    return {position.x, position.y, (float)texture.width, (float)texture.height};
}

