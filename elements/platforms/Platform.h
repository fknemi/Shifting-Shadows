#include <raylib.h>

class Platform {
    private:
        Texture texture;
        Vector2 position;
    public:
    Platform(const char *imagePath, Vector2 imagePosition, float scale);
    ~Platform();
    void draw();

};
