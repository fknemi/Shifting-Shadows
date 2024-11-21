#include <map>
#include <raylib.h>
#include <string>

struct Keybind {
  std::string Title;
  KeyboardKey DefaultKeybind;
  KeyboardKey CurrentKeybind;
};


std::map<std::string, Keybind> Keybinds{
    {"MOVE LEFT", {"MOVE LEFT", KEY_LEFT, KEY_LEFT}},
    {"MOVE RIGHT", {"MOVE RIGHT", KEY_RIGHT, KEY_RIGHT}},
    {"JUMP", {"JUMP", KEY_UP, KEY_UP}},
    {"CAMOUFLAGE", {"CAMOUFLAGE", KEY_RIGHT_SHIFT, KEY_RIGHT_SHIFT}},
    {"USE TONGUE", {"USE TONGUE", KEY_V, KEY_V}},
    {"GRAB TONGUE", {"GRAB TONGUE", KEY_B, KEY_B}},
    {"TOGGLE FULLSCREEN", {"TOGGLE FULLSCREEN", KEY_F11, KEY_F11}}};


