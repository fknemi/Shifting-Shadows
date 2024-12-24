#include <filesystem>
#include <iostream>

int main() {
  std::string path = std::filesystem::current_path();
  std::cout << path;
  return 0;
}

