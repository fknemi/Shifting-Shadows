#include <string>
#include <vector>
#include <raylib.h>

struct Keybind {
    std::string Title;
    KeyboardKey DefaultKeybind;
    KeyboardKey CurrentKeybind;
};


std::vector<Keybind> Keybinds = {
    {
        "MOVE LEFT",
        KEY_LEFT,
        KEY_LEFT
    },
   {
        "MOVE RIGHT",
        KEY_RIGHT,
        KEY_RIGHT
    },
   {
        "JUMP",
        KEY_UP,
        KEY_UP
    },
   {
       "CAMOUFLAGE",
        KEY_RIGHT_SHIFT,
        KEY_RIGHT_SHIFT
   },
   {
       "USE TONGUE",
       KEY_V,
       KEY_V
   },
   {
       "GRAB TONGUE",
       KEY_B,
       KEY_B
   },
   {
       "TOGGLE FULLSCREEN",
       KEY_F11,
       KEY_F11
   }
};
