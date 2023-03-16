#include <algorithm>
#include <iostream>
#include <vector>

#include "boxcontainer.h"

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec) {
  out << " [ ";
  for (auto i : vec) {
    out << i << ' ';
  }
  out << ']';
  return out;
}

int main()
{
  // Source collection
  std::vector<int> numbers{1, 9, 3, 8, 7, 2, 5, 4, 6, 89};
  std::cout << "numbers : " << numbers << std::endl;

  BoxContainer<int> box1;
  box1.add(5);
  box1.add(1);
  box1.add(4);
  box1.add(8);
  box1.add(5);
  box1.add(3);
  box1.add(7);
  box1.add(9);
  box1.add(6);

  std::cout << "box : " << box1 << std::endl;

  // Iterators returned by begin() are input iterators. The requirement is that we
  // able to read through them. That's all std::ranges::find needs.
  // Show possible implementations at cppreference.
  if (std::ranges::find(box1, 8) != box1.end()) {
    std::cout << "numbers contains: " << 8 << '\n';
  } else {
    std::cout << "numbers does not contain: " << 8 << '\n';
  }

  // Range based for loop

  /*
  for (auto n : box1) {
    std::cout << n << ' ';
  }
  std::cout << ' ';
  */

  // std::ranges:reverse(box1.begin(), box1.end());

  return 0;
}
