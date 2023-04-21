#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

#include "boxcontainer.h"

template <typename T>
// NEW_FOR_ME to use const BoxContainer we should define constant iterator of out custom container
// otherwise we will get error: passing 'const BoxContainer<int>' as 'this' argument discards qualifiers
void print(const BoxContainer<T>& c) { // REASON 1 to have constant iterator: passing constant container
  for (auto i : c) { // Computation happens here.
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int main() {
  BoxContainer<int> vi;
  vi.add(5);
  vi.add(1);
  vi.add(7);
  vi.add(2);
  vi.add(5);
  vi.add(3);
  vi.add(7);
  vi.add(9);
  vi.add(6);

  const BoxContainer<int> copy(vi);

  std::cout << "data : ";
  // NEW_FOR_ME without defining constant iterator for custom container BoxContainer
  // we will get error: passing 'const BoxContainer<int>' as 'this' argument discards qualifiers
  for (auto it = copy.begin(); it != copy.end(); ++it) { // REASON 2 to have constant iterator: iterating constant container
    std::cout << (*it) << " ";
  }
  std::cout << std::endl;

  print(copy);

  return 0;
}