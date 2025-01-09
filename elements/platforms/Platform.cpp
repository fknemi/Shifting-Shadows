#include "Platform.h"
#include "../../Player.h"
#include <raylib.h>


Platform::Platform(const char *imagePath, Vector2 imagePosition, float scale){
    texture = LoadTexture(imagePath);
    position = imagePosition;
}

Platform::~Platform(){
    UnloadTexture(texture);
}

void  Platform::draw(){
    DrawTexture(texture, position.x, position.y - texture.height, WHITE);
}
Rectangle Platform::getSize(){
    return {position.x, position.y, (float)texture.width, (float)texture.height};
}


bool isNotVisible(Platform b, int targetX, int targetY){
    Rectangle size = b.getSize();
if(size.x + size.width){
return true;
}

}

