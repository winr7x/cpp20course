
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

template <typename T>
class VectorWrapper{
public:
  //Iterator methods
  // NEW_FOR_ME way to make wrapper around std::vector
  std::vector<T>::iterator begin() { return m_items.begin(); }
  std::vector<T>::iterator end()   { return m_items.end(); }

  //Const overloads
  std::vector<T>::const_iterator begin() const{ return m_items.cbegin(); }
  std::vector<T>::const_iterator end() const  { return m_items.cend(); }

  std::vector<T>::const_iterator cbegin() { return m_items.cbegin(); }
  std::vector<T>::const_iterator cend()   { return m_items.cend(); }

  friend std::ostream& operator<< (std::ostream& out, const VectorWrapper<T>& vec){
    out << "Items : " ;
    for (auto i : vec.m_items){
      out << i << " <---> ";
    }
    return out;
  }

  // The single new method in wrapper we want to add to the std::vector
  void my_add( T item){
      m_items.push_back(item);
  }
private :
  std::vector<T> m_items;
};

int main() {
  VectorWrapper<std::string> greeting;
  greeting.my_add("Hello"); // Using of new method in wrapper
  greeting.my_add("World!");
  greeting.my_add("How");
  greeting.my_add("are");
  greeting.my_add("you");
  greeting.my_add("all");
  greeting.my_add("doing?");

  std::cout << "greeting : " << greeting << std::endl;

  std::cout << "\nRange based for loop : " << std::endl;
  for (auto i : greeting) {
    std::cout << i << " <--> ";
  }
  std::cout << std::endl;

  std::cout << "\ntaking only 2 : " << std::endl;
  for (auto i : greeting | std::views::take(2)) {
    std::cout << i << " <--> ";
  }
  std::cout << std::endl;

  return 0;
}