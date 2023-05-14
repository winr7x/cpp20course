#include <iostream>
#include <memory>

#include "dog.h"
#include "person.h"

int main(){
	// Playing with basic use of weak_ptr
    std::shared_ptr<Dog> shared_ptr_dog_1 = std::make_shared<Dog>("Dog1");
    std::shared_ptr<int> shared_ptr_int_1 = std::make_shared<int>(200);
    
    std::weak_ptr<Dog>  weak_ptr_dog_1 (shared_ptr_dog_1); // Way to create weak_ptr<>
    std::weak_ptr<int>  weak_ptr_int_1 (shared_ptr_int_1);

    // No * , or -> operators you would expect from regular pointers
    //std::cout << "weak_ptr_dog_1 use count : " << weak_ptr_dog_1.use_count() << std::endl;
    // std::cout << "Dog name : " << weak_ptr_dog_1->get_name() << std::endl; // NEW_FOR_ME UNCOMMENT_TO_SEE error: base operand of '->' has non-pointer type 'std::weak_ptr<Dog>'
    // std::cout << "Pointed to value : " << *weak_ptr_int_1 << std::endl; // NEW_FOR_ME UNCOMMENT_TO_SEE error: no match for 'operator*' (operand type is 'std::weak_ptr<int>')
    // std::cout << "Pointed to address : " << weak_ptr_dog_1.get() << std::endl; // NEW_FOR_ME UNCOMMENT_TO_SEE error: 'class std::weak_ptr<Dog>' has no member named 'get'


	// To use a weak ptr you have to turn it into a shared_ptr with the lock method
	std::cout << std::endl;
    std::shared_ptr<Dog> weak_turned_shared = weak_ptr_dog_1.lock(); // NEW_FOR_ME Way to use existing weak_ptr<>
    std::cout << "weak_turned_shared use count : " << weak_turned_shared.use_count() << std::endl;
    std::cout << "Dog name : " << weak_turned_shared->get_name() << std::endl;
	std::cout << "Dog name : " << shared_ptr_dog_1->get_name() << std::endl;


    // Cycling dependency problem
	// Circular dependencies
	std::shared_ptr<Person> person_a = std::make_shared<Person>("Alison");
    std::shared_ptr<Person> person_b = std::make_shared<Person>("Beth");
    
    person_a->set_friend(person_b);
    person_b->set_friend(person_a);
	
    
    return 0;
}