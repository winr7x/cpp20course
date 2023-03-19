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

  std::cout << "box1 : " << box1 << std::endl;
  std::ranges::replace(box1.begin(), box1.end(), 7, 777);
  std::ranges::replace(std::begin(box1), std::end(box1), 7, 777);
  std::cout << "box1 : " << box1 << std::endl;

  return 0;
}
