// https://youtu.be/8jLOx1hD3_o?t=16687

#include <iostream>
#include <string>

int main() {
  int var1{123}; // Declare and initialize
  std::cout << "var1 : " << var1 << std::endl;

  var1 = 55;
  std::cout << "var1 : " << var1 << std::endl;

  std::cout << std::endl;

  std::cout << "--------------------" << std::endl;

  double var2{44.55}; // Declare and initialize
  std::cout << "var2 : " << var2 << std::endl;

  var2 = 99.99; // Assign
  std::cout << "var2 : " << var2 << std::endl;

  std::cout << std::endl;

  std::cout << "--------------------" << std::endl;

  bool state{false}; // Declare and initialize
  std::cout << std::boolalpha;
  std::cout << "state : " << state << std::endl;

  state = true; // Assign

  std::cout << "state : " << state << std::endl;

  std::cout << std::endl;

  std::cout << "--------------------" << std::endl;

  // Auto type deduction
  // Careful about auto assignments
  [[maybe_unused]] auto var3{333u}; // Declare and initializewith type deduction

  // var3 = -22; // Assign negative number. DANGER! UNCOMMENT_TO_SEE warning C4245: '=': conversion from 'int' to 'unsigned int'

  // std::cout << "var3 : " << var3 << std::endl; // It will print 4294967274

  return 0;
}
