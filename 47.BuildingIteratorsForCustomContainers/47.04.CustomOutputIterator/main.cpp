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

  // Destination box
  BoxContainer<int> box2;
  for (size_t i{}; i < box1.size(); ++i) {
    box2.add(0);
  }

  std::cout << "box2-1 : " << box2 << std::endl;
  
  // std::copy without range
  std/*::ranges*/::copy(box1.begin(), box1.end(), box2.begin());
  
  // std::copy with range begin() and end()
  std::ranges::copy(box1.begin(), box1.end(), box2.begin());
  
  // std::copy without range simplest
  std::ranges::copy(box1, box2.begin());
  std::cout << "box2-2 : " << box2 << std::endl;

  return 0;
}
