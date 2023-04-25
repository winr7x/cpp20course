#include <iostream>
#include <array>


class Item{
public : 
    Item() :m_var(0){
        std::cout << " Item default constructor called" << std::endl;
    }
    Item(int var) : m_var(var){
       // std::cout << "Item constructor called for: " << m_var << std::endl;
    }
    Item(int var1, int var2) : m_var( var1 * var2)
    {
        
    }
    
    Item(const Item& source) : m_var{source.m_var}{
        //std::cout << "Item copy constructor called for :" << m_var << std::endl;
    }
    
    int get() const{
        return m_var;
    }
private : 
    int m_var{0};
};

std::ostream& operator << (std::ostream& out, const Item & item){
    out << "Item[value:" << item.get() << "]";
    return out;
}


template <typename T>
void print_collection(const T& collection){
    
    auto it = collection.begin();
    
    std::cout << " Collection [";
    while(it != collection.end()){
        std::cout << " " << *it ;
        ++it;
    }
    std::cout << "]" << std::endl;
}

template <typename T>
void print_raw_array(const T* p, std::size_t size)
{
    std::cout << " data = ";
    for (std::size_t i = 0; i < size; ++i)
        std::cout << p[i] << ' ';
    std::cout << std::endl;
}



int main(){

   //Code1 : Collection creation and element access
    std::cout << std::endl;
    std::cout << "Collection creation and element access : " << std::endl;

    std::array<int,10> numbers{1,2,3,4,5,6,7,8,9,10};
    //If you put in less than 10, the rest is auto filled with 0 (default constructed value)
    //If you put in more than 10, you get a compiler error. Can't go over that
    
    std::cout << " numbers : " ;
    print_collection(numbers);
    
    //Front and back return references, we can even use them to modify data. Right ? 
    numbers.front() = 22;
    numbers.back()  = 33;
    
    std::cout << " numbers front : "  << numbers.front() << std::endl;
    std::cout << " numbers back : " << numbers.back() << std::endl;
    
    
    std::cout << "-----------------------" << std::endl;
    
    
    //Code4 : Operations
    //Filling
    std::cout << "filling : " << std::endl;
    std::cout << " numbers : " ;
    print_collection(numbers);
    numbers.fill(1000);
    std::cout << " numbers : " ;
    print_collection(numbers);
    
    
    
   
    //Swapping : arrays must be of same size and contain the same type. 
    //otherwise they'll be different types and you can't cross assign different types.
    std::cout << std::endl;
    std::cout << "Swapping : " << std::endl;
    std::array<int,10> other_numbers {5,5,5,5,5,5,5,5,5,5};
    
    std::cout << " numbers : " ;
    print_collection(numbers);
    
    std::cout << " other_numbers : " ;
    print_collection(other_numbers);
    
    //swap
    numbers.swap(other_numbers);
    
    std::cout << " numbers : " ;
    print_collection(numbers);
    
    std::cout << " other_numbers : " ;
    print_collection(other_numbers);
    
    
    
    //Code5 : Can assign arrays to each other
    std::cout << std::endl;
    std::cout << "Assigning arrays to each other :" << std::endl;
    
    std::cout << " numbers : " ;
    print_collection(numbers);
    std::cout << " other_numbers : " ;
    print_collection(other_numbers);
    
    numbers = other_numbers; // Calls the copy assignment operator of std::array
    
    std::cout << " numbers : " ;
    print_collection(numbers);
    std::cout << " other_numbers : " ;
    print_collection(other_numbers);
    
    //This isn't possible with raw arrays.
    [[maybe_unused]] int int_arr1[] {1,2,3};
    [[maybe_unused]] int int_arr2[] {4,5,6};
    // int_arr2 = int_arr1; // NEW_FOR_ME UNCOMMENT_TO_SEE Compiler error : invalid array assignment
    
    
    //Code6 : std::arrays for custom objects
    std::cout << std::endl;
    std::cout << "Storing custom objects in std::array : " << std::endl;
    
    std::array<Item,5> items = {};
    std::cout << " default initialized items : " << std::endl;
    
    std::cout << " items : " ;
    print_collection(items);
    
    items.fill(Item(5));
    
    std::cout << " items : " ;
    print_collection(items);
    
  
  
    return 0;
}