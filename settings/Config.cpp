// TODO: Toggle FPS Overlay, Show Mouse, Keybinds, Audio Make Seperate Files For
// Their Config And In Config.cpp Make Methods to Load At Startup, Save To
// Documents/Shifting Shadows/, Update Them Via Buttons
//
//
//

#include <map>
#include <raylib.h>
#include <string>

struct Config {
  std::string Title = "Shifitng Shadows";
  bool Fullscreen = false;
  bool ShowFPS = false;
  bool ShowMouse = false;
  std::map<std::string, float> Audio = {
      {"MasterVolume", 0.8f}, {"MusicVolume", 0.5f}, {"SFXVolume", 0.7f}};
};




void LoadConfig(){

}
