// https://youtu.be/8jLOx1hD3_o?t=15402

#include <iostream>
#include <string>

int main() {
  bool red_light{false};
  bool green_light{true};

  if (red_light == true) {
    std::cout << "Stop!" << std::endl;
  } else {
    std::cout << "Go throught!" << std::endl;
  }

  if (green_light) {
    std::cout << "The light is green!" << std::endl;
  } else {
    std::cout << "The light is NOT green!" << std::endl;
  }

  // Printing out a bool
  // 1 -->> true
  // 0 -->> false
  std::cout << std::endl;
  std::cout << "red_light : " << red_light << std::endl;
  std::cout << "green_light : " << green_light << std::endl;

  // Print out true and false
  std::cout << std::endl;
  std::cout << std::boolalpha; // Forces the output format to true/false
  std::cout << "red_light : " << red_light << std::endl;
  std::cout << "green_light : " << green_light << std::endl;

  std::cout << std::endl;
  std::cout << "sizeof(bool) : " << sizeof(bool) << std::endl;

  return 0;
}
