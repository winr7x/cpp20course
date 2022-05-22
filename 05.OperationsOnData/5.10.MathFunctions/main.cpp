// https://youtu.be/8jLOx1hD3_o?t=24071

#include <cmath>
#include <iostream>

int main(int argc, char **argv) {
  double weight{7.7};

  // floor
  std::cout << "Weight rounded to floor is : " << std::floor(weight) << std::endl;

  // ceil
  std::cout << "Weight rounded to ceil is : " << std::ceil(weight) << std::endl;

  std::cout << std::endl;

  // abs
  double savings{-5000};
  weight = 7.7;
  std::cout << "Abs of weight is : " << std::abs(weight) << std::endl;
  std::cout << "Abs of savings is : " << std::abs(savings) << std::endl;

  std::cout << std::endl;

  // exp : f(x) = e ^ x , where e = 2.71828 .
  double exponential = std::exp(10);
  double exponential_1 = std::exp(1);
  std::cout << "The exponential of 10 is : " << exponential << std::endl;
  std::cout << "The exponential of 1 is : " << exponential_1 << std::endl;

  std::cout << std::endl;

  // pow
  std::cout << "3 ^ 4 is : " << std::pow(3, 4) << std::endl; // 81
  std::cout << "9^3 is : " << std::pow(9, 3) << std::endl;   // 729

  // log: reverse function of pow. if 2^3 = 8 , log 8 in base 2 = 3. Log is like asking
  //  to which exponent should we elevate 2 to get eight ? Log, by default computes the log
  //  in base e. There also is another function which uses base 10 called log10

  // Try the reverse operation of e^4 = 54.59 , it will be log 54.59 in base e = ?
  std::cout << "Log ; to get 54.59, you would elevate e to the power of : " << std::log(54.59) << std::endl;

  std::cout << std::endl;

  // log10, 10 ^ 4 = 10000 , to get 10k, you'd need to elevate 10 to the power of ? , this is log in base 10
  std::cout << "To get 1000, you'd need to elevate 10 to the power of : " << std::log10(10000) << std::endl;

  // sqrt
  std::cout << "The square root of 81 is : " << std::sqrt(81) << std::endl;

  // round. Halfway points are rounded away from 0. 2,5 is rounded to 5 for example
  std::cout << "3.654 rounded to : " << std::round(3.654) << std::endl;
  std::cout << "2.5 rounded to : " << std::round(2.5) << std::endl;
  std::cout << "2.4 rounded to : " << std::round(2.4) << std::endl;

  return 0;
}
