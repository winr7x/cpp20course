#include <iostream>
#include <memory>

#include "dog.h"

struct A {
	~A() { std::cout << "~A()\n"; }
};

int main(){

	// C++17 only : Recommended
	std::shared_ptr<int[]> shared_ptr_int_arr_1( new int[10]{1,2,3,4,5,6,7,8}); // NEW_FOR_ME way to use shared_ptr with array
	std::shared_ptr<Dog[]> shared_ptr_dog_arr_1( new Dog[10]{Dog("Dog1"),Dog("Dog2")});

	// Setting elements
	shared_ptr_int_arr_1[3] = 28;
	shared_ptr_dog_arr_1[1] = Dog("Fluzzy");

	// Read int array
	std::cout << std::endl;
	std::cout << "Reading data from arrays" << std::endl;
	std::cout << "Reading shared_ptr_int_arr_1: " << std::endl;
	for(size_t i{0}; i < 10 ; ++i){
		std::cout << "shared_ptr_int_arr_1[" << i << "] : " << shared_ptr_int_arr_1[i] << std::endl; // NEW_FOR_ME shared_ptr with array index access
	}
	
	std::cout << std::endl;
	std::cout << "Reading shared_ptr_dog_arr_1: " << std::endl;
	for(size_t i{0}; i < 10 ; ++i){
		std::cout << "shared_ptr_dog_arr_1[" << i << "] : " << shared_ptr_dog_arr_1[i].get_name() << std::endl;
	}

	[[maybe_unused]] std::shared_ptr<A[]> shared_a_1 ( new A[] { A(), A(), A(), A() } );
	[[maybe_unused]] std::shared_ptr<A[]> shared_a_2 ( new A[2] { A(), A() } );

    return 0;
}