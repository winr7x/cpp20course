#include <iostream>
#include "boxcontainer.h"

void populate_box(BoxContainer<int>& box, int modifier){
	for(size_t i{0} ; i < 20 ; ++i){
		box.add((i+1)*modifier);
	}
}

BoxContainer<int> make_box(int modifier){
	BoxContainer<int> local_int_box(20); // Main constructor is called here.
	                                     // capacity=20
	populate_box(local_int_box,modifier);
	return local_int_box;
}


int main(){

	BoxContainer<int> box_array[2]; // Main constructor is called 2 times here.
	                                // capacity=DEFAULT_CAPACITY=5

    std::cout << "--------" << std::endl;

	for(size_t i{0} ; i < 2 ; ++i){
		box_array[i] = make_box(i+1); // Copy assignment operator is called here
									  // We're copying data from the temporary and then
									  // Destructor of the temporary is called here
									  // THIS IS A HUGE WASTE! MOVE SEMANTICS IS REQUIRED HERE
		std::cout << '\n';
	}


    std::cout << "--------" << std::endl;

    // Destructor for box_array[2] is called here
   
    return 0;
}