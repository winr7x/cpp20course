
#include <iostream>

#include <algorithm>
#include <ranges>
#include <vector>

template<typename T>
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
  
  /*
  // Iterators returned by begin() are input iterators. The requirement is that we
  // able to read through them. That's all std::ranges::find needs.
  // Show possible implementations at cppreference.
  if (std::ranges::find(numbers.cbegin(), numbers.cend(), 8) != numbers.cend()) {
    std::cout << "numbers contains: " << 8 << '\n';
  } else {
    std::cout << "numbers does not contain: " << 8 << '\n';
  }
  */

  /*
  // Output iterator : std::ranges::copy
  // Iterator through which we can write
  std::cout << "-------------(copy)------------" << std::endl;
  std::vector<int> dest(numbers.size());
  // std::vector<int> dest; // BAD! Probably a crash
  std::cout << "numbers : " << numbers << std::endl;
  std::cout << "dest : " << dest << std::endl;

  // dest.begin() has to be an output iterator, have to be able to write through it
  //std::ranges::copy(cnumbers.begin(), numbers.cend(), dest.cbegin()); // Compiler Error
                                                                    // is not output iterator
  std::ranges::copy(numbers.cbegin(), numbers.cend(), dest.begin()); // Compiler Error
                                                                    // is not output iterator
  std::cout << "numbers : " << numbers << std::endl;
  std::cout << "dest : " << dest << std::endl;
  */

  /*
  // Forward iterator : std::ranges::replace, std::ranges::fill
  std::cout << "-------------(replace)------------" << std::endl;
  std::cout << "numbers : " << numbers << std::endl;

  // replacing every instance of 7 with 345
  // operator++ to move forward. See possible implementation
  std::ranges::replace(numbers.begin(), numbers.end(), 7, 345);
  std::cout << "numbers : " << numbers << std::endl;
  */

  /*
  // Bidirectional iterator
  std::cout << "-------------(bi-directional)------------" << std::endl;

  std::cout << "numbers : " << numbers << std::endl;
  auto it_first = numbers.begin();
  auto it_last = numbers.end();
  do {
    std::cout << *(-- it_last) << ' ';
  } while (it_last != it_first);

  std::cout << std::endl;
  std::ranges::reverse(numbers);
  std::cout << "numbers : " << numbers << std::endl;
  std::ranges::reverse(numbers.begin(), numbers.end());
  */

  // Random access iterator : std::ranges::sort
  // Contiguous iterator : C++ don't have a concrete example for this
  std::cout << "-------------(sort)------------" << std::endl;
  std::cout << "numbers : " << numbers << std::endl;

  // Sorting the collection
  std::ranges::sort(numbers);
  std::cout << "numbers : " << numbers << std::endl;

  return 0;
}
