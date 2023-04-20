#include <iostream>
#include <vector>
#include <ranges>

int main(){
  // Generate an infinite sequence of numbers
  // NEW_FOR_ME std::views::iota is a range factory.
  // It generates a range of numbers by incrementing initial value.
  auto infinite_view = std::views::iota( // Var stores the compuation
#if 0
                                         1
#else
                                         10
#endif
                                         
#if 1
                                          , 15 // [<start> , 15) // NEW_FOR_ME Upper bound can be set
#endif
                                         ) | std::views::take(20); // take only 20 elements

  // Numbers are generated lazily, on the fly, as we need them in each iteration
  for(auto i : infinite_view ){
      std::cout << i << std::endl;
  }

#if 0 // UNCOMMENT_FOR_ERROR Infinite loop
  for(auto i :std::views::iota(1)) {
      std::cout << i << std::endl;
  }
#endif

  std::cout << std::endl;

  // Another way of using std::views::iota(). Without '|' operator
  auto data_view = std::views::take( std::views::iota(1), 20 );
  for(auto i : data_view ){
      std::cout << i << std::endl;
  }

  std::cout << std::endl;

  // Another way. Directly in loop
      // Without '|' operator
      for(auto i : std::views::take( std::views::iota(1), 7 ) ){
          std::cout << i << std::endl;
      }

      std::cout << std::endl;

      // With '|' operator
      for(auto i : std::views::iota(1) | std::views::take(4) ){
          std::cout << i << std::endl;
      }

  return 0;
}