// https://youtu.be/8jLOx1hD3_o?t=27769

#include <iostream>

int main(int argc, char **argv) {
  int a = 1;
  int b = 2;

  int max = (a > b) ? a : 22.5f; // NEW_FOR_ME warning: implicit conversion from 'float' to 'int' changes value from 22.5 to 22

  std::cout << "max : " << max << std::endl;

  // int max2 { (a > b) ? a : 22.5f }; // UNCOMMENT_FOR_ERROR error: type 'float' cannot be narrowed to 'int' in initializer list
  //                                                          note: insert an explicit cast to silence this issue: static_cast<int>((a > b) ? a : 22.5f)

  return 0;
}
