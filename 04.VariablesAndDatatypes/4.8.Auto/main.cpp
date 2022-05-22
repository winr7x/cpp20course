// https://youtu.be/8jLOx1hD3_o?t=16326

#include <iostream>
#include <string>

int main(int argc, char **argv) {
  auto var1{12};    // int
  auto var2{13.0};  // double
  auto var3{14.0f}; // float
  auto var4{15.0l}; // long double !!!
  auto var5{'e'};   // char

  // int modifier suffixes
  auto var6{123u};  // unsigned
  auto var7{123ul}; // unsigned long
  auto var8{123ll}; // long long

  std::cout << "var1 occupies : " << sizeof(var1) << " bytes" << std::endl; // gcc/clang 4  msvc: 4
  std::cout << "var2 occupies : " << sizeof(var2) << " bytes" << std::endl; // gcc/clang 8  msvc: 8
  std::cout << "var3 occupies : " << sizeof(var3) << " bytes" << std::endl; // gcc/clang 4  msvc: 4
  std::cout << "var4 occupies : " << sizeof(var4) << " bytes" << std::endl; // gcc/clang 16 msvc: 8 !!! long double
  std::cout << "var5 occupies : " << sizeof(var5) << " bytes" << std::endl; // gcc/clang 1  msvc: 1
  std::cout << "var6 occupies : " << sizeof(var6) << " bytes" << std::endl; // gcc/clang 4  msvc: 4
  std::cout << "var7 occupies : " << sizeof(var7) << " bytes" << std::endl; // gcc/clang 4  msvc: 4
  std::cout << "var8 occupies : " << sizeof(var8) << " bytes" << std::endl; // gcc/clang 8  msvc: 8

  return 0;
}
