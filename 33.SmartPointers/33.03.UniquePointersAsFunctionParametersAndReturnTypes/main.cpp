#include <iostream>
#include <memory>
#include "dog.h"
#include "person.h"


void do_something_with_dog_v1( std::unique_ptr<Dog> d){
    d->print_info() ;
}


void do_something_with_dog_v2( const std::unique_ptr<Dog>& d){
    d->set_dog_name("Rior");
    // d->print_info();
    // d.reset(); // UNCOMMENT_TO_SEE error: passing 'const std::unique_ptr<Dog>' as 'this' argument discards qualifiers
}


std::unique_ptr<Dog> get_unique_ptr(){
    std::unique_ptr<Dog> p_dog = std::make_unique<Dog>("Function Local");
	std::cout << "unique_ptr address(in) : " << &p_dog << std::endl;
    return p_dog;  // NEW_FOR_ME The compiler does some optimizations and doesn't return a copy here
                   // it's returning something like a reference to the local object.
                   // We can prove this by looking at the address of objects in memory.
                   // This is not standard behavior, some compilers may actually return 
                   // by value by making a copy. The compilers have some freedom to choose
                   // their own way to do things.
}

int main(){

#if 1 //Passing unique ptr to functions by value
	std::unique_ptr<Dog> p_dog_1 = std::make_unique<Dog>("Dog1");
    
	// Can't pass unique_ptr by value to a function : copies not allowed
    // do_something_with_dog_v1(p_dog_1);   // copy detected // UNCOMMENT_TO_SEE note: declared here unique_ptr(const unique_ptr&) = delete;

    // NEW_FOR_ME Ownership will move to the body of the function and memory will be
    // released when function returns. NOT WHAT YOU TYPICALLY WANT.
	do_something_with_dog_v1(std::move(p_dog_1)); 

    std::cout << "p_dog_1 : " << p_dog_1.get() << std::endl; 
    std::cout << "Hitting back the main function" << std::endl;
#endif

#if 1 // The same behavior when function is part of the class
    std::cout << std::endl;

    std::unique_ptr<Dog> p_dog_2 = std::make_unique<Dog>("Dog2");

    Person person1("John");
    person1.adopt_dog(std::move(p_dog_2)); // call part of class
    std::cout << "Doing something , p_dog_2 points to :  " <<p_dog_2.get() <<  std::endl;
#endif

#if 1 // NEW_FOR_ME An implicit move is done when object is created in place as a temporary
	std::cout << std::endl;
	do_something_with_dog_v1(std::make_unique<Dog>("Temporary Dog"));
#endif

#if 1 // Can pass the std::unique_ptr parameter by reference
	std::cout << std::endl;
	std::unique_ptr p_dog_3 = std::make_unique<Dog>("Dog3");
	p_dog_3->print_info();
	do_something_with_dog_v2(p_dog_3);
	std::cout << "-----" << std::endl;
	p_dog_3->print_info();
#endif

#if 1 // Returning unique ptr from function by value
	std::cout << std::endl;
	std::unique_ptr<Dog> p_dog_4 = get_unique_ptr();
	std::cout << "delimiter" << std::endl;
	std::cout << "unique_ptr address(out) : " << &p_dog_4 << " return value optimization" << std::endl;

	p_dog_4->print_info();
#endif

    std::cout << std::endl;

    get_unique_ptr()->print_info();

    std::cout << "get_unique_ptr() function done. Temporary object is destroyed to this moment\n" << std::endl;

    return 0;
}