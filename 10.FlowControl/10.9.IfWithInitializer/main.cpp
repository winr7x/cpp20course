// 78. If with Initializer

#include <iostream>

int main() {

  const bool go {true};

  // With if initializer
  if (const int high_speed{33}, fake_var{-200}; go) { // NEW_FOR_ME Initialize variable in if

    if (high_speed > 5) {
      std::cout << "Slow down!" << std::endl;
    } else {
      std::cout << "All good!" << std::endl;
    }

    std::cout << "Also fake_var == " << fake_var << std::endl;

  } else {
    std::cout << "high_speed : " << high_speed << std::endl;
    std::cout << "Stop" << std::endl;
    std::cout << "Also fake_var == " << fake_var << std::endl;
  }

  // std::cout << "high_speed : " << high_speed << std::endl; // UNCOMMENT_FOR_ERROR 'high_speed': undeclared identifier

  return 0;
}