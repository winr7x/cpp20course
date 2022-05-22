// https://youtu.be/8jLOx1hD3_o?t=12113

#include <iostream>
#include <string>

int main(int argc, char **argv) {
  // Variable may contain random garbage value. WARNING
  int elephant_count;

  int lion_count{}; // Initializes to zero

  int dog_count{10}; // Initializes to 10

  int cat_count{15}; // Initializes to 15

  // Can use expression as initializer
  int domesticated_animals{dog_count + cat_count};

  // Won't compile, the expression in the braces uses undeclared variables
  // int bad_initialization { doesnt_exist1 + doesnt_exist2 }; // UNCOMMENT_FOR_ERROR

  // 2.9 is of type double, with a wider range than int. ERROR OR WARNING.
  // int narrowing_conversation {2.9}; // UNCOMMENT_FOR_ERROR

  std::cout << elephant_count << std::endl;
  int functional_initialization(10);
  std::cout << sizeof(int) << ' ' << sizeof(elephant_count) << '\n';

  return 0;
}