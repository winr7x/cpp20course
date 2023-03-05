#include <iostream>

import math.add_sub; // NEW_FOR_ME Way to simulate submodules. 
                     // math.add_sub is just a name of separate module "math.add_sub"
                     // which is declared in file add_sub.ixx
import math.mult_div;

// import math;      // math is also separate module which forward two other separate modules
                     // math.add_sub and math.mult_div for importers

int main() {
  auto addResult = add(10, 20);
  std::cout << "add result : " << addResult << std::endl;

  auto multResult = mult(10, 20);
  std::cout << "mult result : " << multResult << std::endl;
}