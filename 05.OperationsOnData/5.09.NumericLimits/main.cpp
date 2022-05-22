// https://youtu.be/8jLOx1hD3_o?t=23607

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

int main(int argc, char **argv) {
  std::cout << "short:\n";
  std::cout << "  lowest:" << std::numeric_limits<short>::lowest() << std::endl;
  std::cout << "  min:" << std::numeric_limits<short>::min() << std::endl;
  std::cout << "  max:" << std::numeric_limits<short>::max() << std::endl;

  std::cout << std::endl;

  std::cout << "int:\n";
  std::cout << "  lowest:" << std::numeric_limits<int>::lowest() << std::endl;
  std::cout << "  min:" << std::numeric_limits<int>::min() << std::endl;
  std::cout << "  max:" << std::numeric_limits<int>::max() << std::endl;

  std::cout << std::endl;

  std::cout << "long long:\n";
  std::cout << "  lowest:" << std::numeric_limits<long long>::lowest() << std::endl;
  std::cout << "  min:" << std::numeric_limits<long long>::min() << std::endl;
  std::cout << "  max:" << std::numeric_limits<long long>::max() << std::endl;

  std::cout << std::endl;

  std::cout << "float:\n";
  std::cout << "  lowest:" << std::numeric_limits<float>::lowest() << std::endl;
  std::cout << "  min:" << std::numeric_limits<float>::min() << std::endl;
  std::cout << "  max:" << std::numeric_limits<float>::max() << std::endl;

  std::cout << std::endl;

  std::cout << "double:\n";
  std::cout << "  lowest:" << std::numeric_limits<double>::lowest() << std::endl;
  std::cout << "  min:" << std::numeric_limits<double>::min() << std::endl;
  std::cout << "  max:" << std::numeric_limits<double>::max() << std::endl;

  std::cout << std::endl;

  std::cout << "long double:\n";
  std::cout << "  lowest:" << std::numeric_limits<long double>::lowest() << std::endl;
  std::cout << "  min:" << std::numeric_limits<long double>::min() << std::endl;
  std::cout << "  max:" << std::numeric_limits<long double>::max() << std::endl;

  std::cout << std::endl;

  // Other facilites
  std::cout << "int is signed : " << std::numeric_limits<int>::is_signed << std::endl;

  std::cout << std::endl;

  // ::digits - number of radix digits that can be represented without change (What does it mean?)
  //   For integers radix is 2
  //   For integer types, this is the number of bits not counting the sign bit and the padding bits (if any).
  //   Padding bits - bits which makes the object bigger. small space waste can generate huge performance gains
  //   In some cases it is essential because the CPU can't handle working with objects of that size.
  std::cout << "bool digits : " << std::numeric_limits<bool>::digits << std::endl; // padding bits
  std::cout << "unsigned short digits : " << std::numeric_limits<unsigned short>::digits << std::endl;
  std::cout << "short digits : " << std::numeric_limits<short>::digits << std::endl; // sign bit
  std::cout << "unsigned int digits : " << std::numeric_limits<unsigned int>::digits << std::endl;
  std::cout << "int digits : " << std::numeric_limits<int>::digits << std::endl; // sign bit

  std::cout << std::endl;

  std::cout << "int radix : " << std::numeric_limits<int>::radix << std::endl;

  return 0;
}
