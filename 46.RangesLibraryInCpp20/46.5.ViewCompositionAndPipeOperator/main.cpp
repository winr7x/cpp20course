
#include <algorithm>
#include <iostream>
#include <map>
#include <ranges>
#include <vector>
#include <unordered_map>

void print(auto view) {
  for (auto i : view) { // Computation happens here.
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int main() {

  std::vector<int> vi {1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Filter out evens and square them out.

  std::cout << "vi : ";
  print(vi);
  std::cout << std::endl;

  // V1 : Raw function composition
  auto even = [](int n) { return n % 2 == 0; };
  // NEW_FOR_ME transform() gets filter() as an argument. Way of function composition.
  auto my_view = std::views::transform(std::views::filter(vi, even), [](auto n){return n*=n;});
  std::cout << "vi transformed : ";
  print(my_view);

  std::cout << std::endl;
  std::cout << "Pipe operator : " << std::endl;
  // NEW_FOR_ME Syntax sugar '|' for function composition. The result is same as above.
  auto my_view1 = vi | std::views::filter(even)
                       | std::views::transform([](auto n){return n *= n;});
  std::cout << "vi transformed : ";
  print(my_view1);

#define USE_UNORDERED_MAP 0

   // classroom done as map : Keys are sorted by default
#if USE_UNORDERED_MAP
  std::unordered_map<std::string, unsigned int> classroom    {
#else
  std::map<std::string, unsigned int> classroom    {
#endif
                                                        {"John", 11},
                                                        {"Mary", 17},
                                                        {"Steve", 15},
                                                        {"Lucy", 14},
                                                        {"Ariel", 12}
                                                    };

  // Print out the names
#if 0
  // Way without '|' operator
  auto names_view = std::views::keys(classroom);
#else
  // NEW_FOR_ME '|' operator for std::views::keys 
  auto names_view = classroom | std::views::keys;
#endif
  std::cout << "names : ";
  std::ranges::copy(names_view, std::ostream_iterator<std::string>(std::cout, " "));


  // Print out the ages : 
  std::cout << std::endl;
  auto ages_view = std::views::values(classroom);
  std::cout << "ages : " ;
  std::ranges::copy(ages_view, std::ostream_iterator<unsigned int>(std::cout," "));


  // Print names in reverse : this doesn't work if you store the data in an 
  // unordered_map. The reason in the unoredered_map doesn't have reverse iterators,
  // that are needed to set up a reverse view.
  std::cout << std::endl;

#if !USE_UNORDERED_MAP // UNCOMMENT_FOR_ERROR std::views::reverse will fail with unordered_map
  std::cout << "names in reverse : ";
  // NEW_FOR_ME '|' operator for std::views::reverse
  std::ranges::copy(std::views::keys(classroom) | std::views::reverse, 
                              std::ostream_iterator<std::string>(std::cout, " "));
#endif

  //Pick names that come before the letter "M" in the alphabet
  std::cout << std::endl;
  auto before_M = [](const std::string& name){
      return  static_cast<unsigned char>(name[0])
                < static_cast<unsigned char>('M');
  };

  std::cout << "names before M : ";
  std::ranges::copy(classroom | std::views::keys | std::views::filter(before_M),
              std::ostream_iterator<std::string>(std::cout, " "));
  
  //Pick names that come after or with the letter "M" in the alphabet
  std::cout << std::endl;
  auto after_M = [](const std::string& name){
      return  static_cast<unsigned char>(name[0])
                >= static_cast<unsigned char>('M');
  };
  std::cout << "names after or with M : ";
  std::ranges::copy(classroom | std::views::keys | std::views::filter(after_M),
              std::ostream_iterator<std::string>(std::cout, " "));

  return 0;
}