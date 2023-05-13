#include <iostream>
#include <memory>

#include "dog.h"

std::unique_ptr<Dog> get_unique_ptr(){
     std::unique_ptr<Dog> dog_ptr_internal = std::make_unique<Dog>("Phil");
     return dog_ptr_internal;
}

int main(){

	std::unique_ptr<int> unique_ptr_int_1 = std::make_unique<int>(22);
	std::unique_ptr<Dog> unique_ptr_dog_1 = std::make_unique<Dog>("Halz");

	//Ownership moves from unique_ptrs to shared_ptrs
	std::shared_ptr<int> shared_ptr_int_1 = std::move(unique_ptr_int_1);
	std::shared_ptr<Dog> shared_ptr_dog_1 = std::move(unique_ptr_dog_1);
	// std::shared_ptr<Dog> shared_ptr_dog_2 = unique_ptr_dog_1;  // NEW_FOR_ME UNCOMMENT_TO_SEE error: conversion from 'std::unique_ptr<Dog>' to non-scalar type 'std::shared_ptr<Dog>' requested
																  // Direct assignment doesn't work, you have to do an explicit std::move to move ownership

	// Can't transform from std::shared_ptr to std::unique_ptr
    // Compiler prevents you from makeing unique_ptr from shared_ptr because shared_ptr can have several copies throughout the project
	// So unique_ptr will not unique
	// std::unique_ptr<int> unique_ptr_illegal_3 = std::move(shared_ptr_int_1); // NEW_FOR_ME UNCOMMENT_TO_SEE error: conversion from std::shared_ptr<int> to non-scalar type 'std::unique_ptr<int>' requested
	

	// NEW_FOR_ME Returning unique_ptr is flexible, because the returned value can be assigned to both unique_ptr and shared_ptr

	//Returning unique_ptr to unique_ptr
	std::cout << std::endl;
	std::cout << "Returning unique_ptr from function to unique ptr" << std::endl;
	std::unique_ptr<Dog> unique_ptr_dog_2 = get_unique_ptr(); // NEW_FOR_ME This implicitly moves ownership to dog_ptr9_unique
	if(unique_ptr_dog_2)
		std::cout << "unique_ptr_dog_2 dog name : " << unique_ptr_dog_2->get_name() << std::endl;
		
	
	//Returning unique_ptr to shared_ptr
	std::cout << std::endl;
	std::cout << "Returning unique_ptr from function to shared ptr" << std::endl;
	std::shared_ptr<Dog> shared_ptr_dog_4 = get_unique_ptr(); // This implicitly moves
						// ownership to shared_ptr_dog_4. Implicitly does something
						//like this : 
						// std::shared_ptr<Dog> shared_ptr_dog_4 = std::move(dog_ptr_internal);
						//moving ownership to a shared pointer whose reference count becomes 1.
	if(shared_ptr_dog_4){
		std::cout << "shared_ptr_dog_4 name 	 : " << shared_ptr_dog_4->get_name() << std::endl;
	}
   
    return 0;
}