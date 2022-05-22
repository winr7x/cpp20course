// 77. If constexpr

#include <iostream>

int main() {
  const int a = 1;
  const int b = 2;

  if constexpr (a < b) { // NEW_FOR_ME Evaluate if at compile time
    std::cout << "a < b\n";
  }

  return 0;
}