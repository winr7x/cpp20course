// https://youtu.be/8jLOx1hD3_o?t=19905

#include <iostream>
#include <string>

int main(int argc, char **argv) {
  int number1{20};
  int number2{20};

  std::cout << "number1 : " << number1 << std::endl;
  std::cout << "number2 : " << number2 << std::endl;

  std::cout << std::endl;
  std::cout << "Comparing variables" << std::endl;

  std::cout << std::boolalpha; // Make bool show up as true/false instead of 1/0
  // Stress the need for parentheses here

  std::cout << std::boolalpha;
  std::cout << "number1 < number2 : " << (number1 < number2) << std::endl;
  std::cout << "number1 <= number2 : " << (number1 <= number2) << std::endl;
  std::cout << "number1 > number2 : " << (number1 > number2) << std::endl;
  std::cout << "number1 >= number2 : " << (number1 >= number2) << std::endl;
  std::cout << "number1 == number2 : " << (number1 == number2) << std::endl;
  std::cout << "number1 != number2 : " << (number1 != number2) << std::endl;

  // UNCOMMENT_FOR_ERROR '<<'-operation priority is higher than '<'-operation
  // std::cout << "number1 < number2 : " << number1 < number2 << std::endl;

  std::cout << std::endl;
  std::cout << "store comparison result and use it later" << std::endl;

  bool result = (number1 == number2);

  std::cout << std::noboolalpha; // NEW_FOR_ME Way to disable boolalpha
  std::cout << number1 << " == " << number2 << " : " << result << std::endl;

  return 0;
}
