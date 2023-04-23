#include <array>
#include <experimental/array>
#include <iostream>

template <typename T,size_t Size> // The second template argument has to be a size.
void print_array( const std::array<T,Size>& arr){
    for(size_t i{}; i < arr.size();++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;    
}

template <typename T>
void print_raw_array(const T* p, std::size_t size)
{
    std::cout << "data = ";
    for (std::size_t i = 0; i < size; ++i)
        std::cout << p[i] << ' ';
    std::cout << std::endl;
}


int main(){

    std::array<int, 3> int_array1; // NEW_FOR_ME Will contain junk by default
    std::array<int, 3> int_array2{ 1,2 }; // Will contain 1,2,0
    std::array<int, 3> int_array3{}; // Will contain 0 0 0
    std::array int_array4{ 1,2 }; // NEW_FOR_ME Compiler will deduce std::array<int,2>
    //std::array<int, 3> int_array5{1,2,3,4,5}; // UNCOMMENT_TO_SEE Compiler error : More than enough elements
    //Can deduce the type with auto.
    auto int_array6 = std::experimental::make_array(1, 2, 3, 4, 5); // NEW_FOR_ME make_array()

    std::cout << "int_array1 : " ;
    print_array(int_array1);
    
    std::cout << "int_array2 : " ;
    print_array(int_array2);
    
    std::cout << "int_array3 : " ;
    print_array(int_array3);
    
    std::cout << "int_array4 : " ;
    print_array(int_array4);
    
    std::cout << "int_array6 : " ;
    print_array(int_array6);


    //Adding and removing stuff
    //Can't really add stuff. Can specify content at initialization
    //Can also fill the entire array with an element
    std::cout << std::endl;
    std::cout << "Filling the array : " << std::endl;
    int_array1.fill(321); // NEW_FOR_ME fill()
    int_array4.fill(500);
    std::cout << "int_array1 : " ;
    print_array(int_array1);
    std::cout << "int_array4 : " ;
    print_array(int_array4);


    //Accessing elements
    std::cout << std::endl;
    std::cout << "Accessing elements in an array: " << std::endl;
    std::cout << "int_array2[0] : " << int_array2[0] << std::endl;
    std::cout << "int_array2.at(1) : " << int_array2.at(1) << std::endl;
    // int_array2[9999]; // NEW_FOR_ME Accessing a nonexistent element through this operator is undefined behavior.
    try {
        int_array2.at(99999999);
    } catch(const std::exception& e) {
        std::cerr << "int_array2.at(99999999) : " << e.what() << '\n';
    }
    
    std::cout << "int_array2.front() : " << int_array2.front() << std::endl;
    std::cout << "int_array2.back() : " << int_array2.back() << std::endl;
    //data method
    print_raw_array(int_array2.data(),int_array2.size()); // NEW_FOR_ME data() method like in std::vector
   
    return 0;
}