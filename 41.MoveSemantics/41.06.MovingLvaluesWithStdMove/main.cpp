#include <iostream>
#include "boxcontainer.h"

void populate_box(BoxContainer<int>& box, int modifier){
	for(size_t i{0} ; i < 20 ; ++i){
		box.add((i+1)*modifier);
	}
}

template<class T>
void swap_data(T& a, T& b) 
{ 
  // T temp { a }; // invokes copy constructor
     T temp { std::move(a) }; std::cout << "temp.constructor(&& a) has been called\n";

  // a = b; // invokes copy assignment
     a = std::move(b);        std::cout << "a.operator=(&& b) has been called\n";

  // b = temp; // invokes copy assignment
     b = std::move(temp);     std::cout << "b.operator=(&& temp) has been called\n";
}

int main(){

	BoxContainer<int> box1;
	populate_box(box1,2);

	BoxContainer<int> box2;
	populate_box(box2,15);
	
	std::cout << "box1 : " << box1 << std::endl;
	std::cout << "box2 : " << box2 << std::endl;
	
	std::cout << "-----" << std::endl;

	swap_data(box1,box2);

  	std::cout << "-----" << std::endl;

	std::cout << "box1 : " << box1 << std::endl;
	std::cout << "box2 : " << box2 << std::endl;

    return 0;
}