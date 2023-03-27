#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

void print(auto view) { // NEW_FOR_ME auto as a parameter type
  for (auto i : view) { // Computation happens here
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

struct Student {
  friend std::ostream& operator<<(std::ostream& out, const Student& s) {
    out << "Student [ name : " << s.m_name << ", age : " << s.m_age << ']';
    return out;
  }
  auto operator <=>(const Student& s) const = default;
  std::string m_name;
  unsigned int m_age;
};

int main() {

  std::vector<int> vi {1, 2, 3, 4, 5, 6, 7, 8, 9};

  // std::ranges::filter_view
  std::cout << std::endl;
  std::cout << "std::ranges::filter_view : " << std::endl;
  auto evens = [](int i) {
    return i % 2 == 0;
  };

  std::cout << "vi : ";
  print(vi);
  // NEW_FOR_ME Way to view on container via custom filter. vi is stayed intact
  std::ranges::filter_view v_evens = std::ranges::filter_view(vi, evens); // No computation

  std::cout << "vi evens : ";
  print(v_evens); // Computation happens in the print function

  // Print evens on the fly
  std::cout << "vi evens : ";
  print(std::ranges::filter_view(vi, evens));

  // Print odds on the fly
  std::cout << "vi odds : ";
  print(std::ranges::filter_view(vi, [](int i) {
    return i % 2 != 0;
  }));

  std::cout << "vi : ";
  print(vi);


  // std::ranges::transform_view
  std::cout << std::endl;
  std::cout << "std::ranges::transform_view : " << std::endl;
  // NEW_FOR_ME Way to view on container via transform view. Container is stayed intact
  std::ranges::transform_view v_transformed = std::ranges::transform_view(vi, [](int i) {
    return i * 10;
  });
  std::cout << "vi : ";
  print(vi);

  std::cout << "vi transformed : " << std::endl;
  print(v_transformed);

  std::cout << "vi : ";
  print(vi);

  // std::ranges::take_view
  std::cout << std::endl;
  std::cout << "std::ranges::take_view : " << std::endl;
  // NEW_FOR_ME Way to view on container via take-1st-N-elements view. Container is stayed intact
  std::ranges::take_view v_taken = std::ranges::take_view(vi, 5);
  std::cout << "vi : ";
  print(vi);
  std::cout << "vi taken : ";
  print(v_taken);

  // is met
  std::cout << std::endl;
  std::cout << "std::ranges::take_while : " << std::endl;
  // NEW_FOR_ME Way to view on container via take_while-1st-elements-are-predicate-true view. Container is stayed intact
  vi = {1, 11, 23, 131, 2, 3, 4, 5, 6, 7, 8, 9};
  std::ranges::take_while_view v_taken_while = std::ranges::take_while_view(vi, [](int i) {
    return i % 2 != 0;
  });
  std::cout << "vi : ";
  print(vi);
  std::cout << "vi taken while : ";
  print(v_taken_while);
  std::cout << "vi : ";
  print(vi);

  // std::ranges::drop_view : drop n first elements
  std::cout << std::endl;
  std::cout << "std::ranges::drop_view : " << std::endl;
  vi = {1, 11, 23, 131, 2, 3, 4, 5, 6, 7, 8, 9};
  // NEW_FOR_ME Way to view on container via drop-1st-N-elements view. Container is stayed intact
  std::ranges::drop_view v_drop = std::ranges::drop_view(vi, 5);
  std::cout << "vi : ";
  print(vi);
  std::cout << "vi drop : ";
  print(v_drop);
  std::cout << "vi : ";
  print(vi);

  // std::views::drop_while_view : drops elements as long as the predicate is met
  std::cout << std::endl;
  std::cout << "std::views::drop_while_view : " << std::endl;
  vi = {1, 11, 23, 4, 2, 3, 4, 5, 6, 7, 8, 9};
  // NEW_FOR_ME Way to view on container via drop_while-1st-elements-are-predicate-true view. Container is stayed intact
  std::ranges::drop_while_view v_drop_while = std::ranges::drop_while_view(vi, [](int i) {
    return i % 2 != 0;
  });
  std::cout << "vi : ";
  print(vi);
  std::cout << "vi drop while : ";
  print(v_drop_while);
  std::cout << "vi : ";
  print(vi);

  // std::ranges::keys_view and std::ranges_value_view
  // Compiler error which I don't understand the reason for yet.

  std::cout << std::endl;
  using pair = std::pair<int, std::string>;
  std::vector<pair> numbers{{1, "one"}, {2, "two"}, {3, "three"}};

  // Compile error when you build views explicitly. Don't understand why yet
  // auto k_view = std::ranges::keys_view(numbers);
  // auto v_view = std::ranges::values_view(numbers);

  // NEW_FOR_ME Way to view on container's keys only. Container is stayed intact
  auto k_view = std::views::keys(numbers);
  // NEW_FOR_ME Way to view on container's values only. Container is stayed intact
  auto v_view = std::views::values(numbers);

  std::cout << "k_view : ";
  print(k_view);

  std::cout << "v_view : ";
  print(v_view);

  std::cout << "numbers : ";
  for (const auto& [key, val] : numbers){
    std::cout << "[key: " << key << " value: " << val << ']';
  };
  std::cout << std::endl;


  // std::views::filter
  vi = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::cout << std::endl;
  std::cout << "std::views::filter : " << std::endl;

  std::cout << "vi : ";
  print(vi);
  // NEW_FOR_ME More convinient std::views::filter() instead of std::ranges::filter_view()
  std::ranges::filter_view v_evens1 = std::views::filter(vi, evens); // No computation

  std::cout << "vi evens : ";
  print(v_evens1); // Computation happens in the print function

  // Print evens on the fly
  std::cout << "vi evens : ";
  print(std::views::filter(vi, evens));

  // Print odds on the fly
  std::cout << "vi odds : ";
  print(std::views::filter(vi, [](int i) {
    return i % 2 != 0;
  }));

  std::cout << "vi : ";
  print(vi);


  // Students example
  std::cout << std::endl;
  std::cout << "students example : " << std::endl;

  std::vector<Student> class_room { {"Mike", 12}, {"John", 17}, {"Drake", 14}, {"Mary", 16} };
  
  std::cout << std::endl;
  std::cout << "classroom : " << std::endl;
  for (auto &s : class_room) {
    std::cout << "    " << s << std::endl;
  }

  std::ranges::sort(class_room, std::less<>{}, &Student::m_age);

  std::cout << std::endl;
  std::cout << "classroom (after sort) : " << std::endl;
  for (auto &s : class_room) {
    std::cout << "    " << s << std::endl;
  }

  std::cout << "Students under 15 : ";
  // NEW_FOR_ME More convinient std::views::take_while() instead of std::ranges::take_while_view()
  print(std::views::take_while(class_room, [](const Student& s){ return (s.m_age < 15);}));

  // NEW_FOR_ME More convinient
  // std::views::take,       std::views::drop,        std::views::drop_while       instead of
  // std::ranges::take_view, std::ranges::drop_view,  std::ranges::drop_while_view
  (void) std::views::transform(vi, [](int i) { return i * 10; });
  (void) std::views::take(vi, 5);
  (void) std::views::drop(vi, 5);
  (void) std::views::drop_while(vi, [](int i) { return i % 2 != 0; });

  return 0;
}