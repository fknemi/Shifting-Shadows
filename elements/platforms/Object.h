#include <raylib.h>

class Object {
    private:
        Texture texture;
        Vector2 position;
        bool hasCollision = false;
    public:
        Object(const char *imagePath, Vector2 imagePosition, float scale);
        Rectangle getSize();
        ~Object();
        void draw();
        void enableCollision();
        void disableCollision();

};
