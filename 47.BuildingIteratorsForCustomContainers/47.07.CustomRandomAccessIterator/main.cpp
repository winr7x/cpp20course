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

  // std::cout << "box1 : " << box1 << std::endl;
  // std::ranges::reverse(box1.begin(), box1.end());
  // std::cout << "box1 : " << box1 << std::endl;

  std::cout << "box1: " << box1 << std::endl;
  std::ranges::sort(box1.begin(), box1.end());
  std::ranges::sort(box1);
  std::sort(box1.begin(), box1.end());
  std::cout << "box1: " << box1 << std::endl;

  return 0;
}
