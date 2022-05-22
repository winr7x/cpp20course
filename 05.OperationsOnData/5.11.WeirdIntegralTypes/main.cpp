// https://youtu.be/8jLOx1hD3_o?t=24864

#include <iostream>

int main(int argc, char **argv) {
  short int var1{10};
  short int var2{20};

  char var3{40};
  char var4{50};

  std::cout << "size of var1 : " << sizeof(var1) << std::endl;
  std::cout << "size of var2 : " << sizeof(var2) << std::endl;
  std::cout << "size of var3 : " << sizeof(var3) << std::endl;
  std::cout << "size of var4 : " << sizeof(var4) << std::endl;

  auto result1 = var1 + var2; // NEW_FOR_ME result1 is of type int. Because integral types less than 4 bytes in size don's support arithmetic operations and compiler implicitly convert expression to smallest type which CPU can do calculation.
  auto result2 = var3 + var4;

  std::cout << "size of result1 : " << sizeof(result1) << std::endl;
  std::cout << "size of result2 : " << sizeof(result2) << std::endl;

  return 0;
}
