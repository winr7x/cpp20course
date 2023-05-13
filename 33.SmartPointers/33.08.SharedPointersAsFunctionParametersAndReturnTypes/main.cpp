#include <iostream>
#include <memory>
#include "dog.h"

// Passing by value. Reference counter is incremented by 1 inside function and decremented after exit
void use_dog_v1([[maybe_unused]] std::shared_ptr<Dog> dog){
}



// Passing by non const reference
// Since no copy is made, we won't see the reference count increment here
// But dog.reset(new Dog()); can be called! Owned object will be replaced
void use_dog_v2([[maybe_unused]] std::shared_ptr<Dog> & dog){
}

// Passing by const reference
// Since no copy is made, we won't see the reference count increment here
// We are protected from But dog.reset(new Dog())
void use_dog_v3([[maybe_unused]] const std::shared_ptr<Dog> & dog){
}


//Returning by value
// NEW_FOR_ME Returning a shared_ptr by value goes through return value optimization and at the
// end no copy is made, we have a single shared ptr with a reference count of 1,
// just like when we create a shared directly with make_shared.
std::shared_ptr<Dog> get_shared_ptr_v1(){
    std::shared_ptr<Dog> dog_ptr = std::make_shared<Dog>("Internal Dog_v1");
	std::cout << "Managed dog address(in) : " << dog_ptr.get() << std::endl;
    return dog_ptr;
}

// #define RETURNING_SHARED_PTR_BY_REF

#ifdef RETURNING_SHARED_PTR_BY_REF
//RETURNING SHARED_PTR BY REF( CONST OR NON CONST) IS A RECIPE
//FOR DISASTER. DON'T DO IT.
//returning std::shared_ptr by reference doesn't properly increment the reference count,
// which opens up the risk of deleting something at the wrong time. We'll get a crash
 std::shared_ptr<Dog>& get_shared_ptr_v2(){
    std::shared_ptr<Dog> dog_ptr = std::make_shared<Dog>("Internal Dog_v2");
    return dog_ptr;
}
#endif

int main(){

  // NEW_FOR_ME address is the same as inside the function due to return value optimization
  std::shared_ptr<Dog> shared_ptr_dog_4 = get_shared_ptr_v1();
  std::cout << "Managed dog address (out) : " << shared_ptr_dog_4.get() << std::endl;


  //Returning by reference : not recommended.
#ifdef RETURNING_SHARED_PTR_BY_REF
  std::shared_ptr<Dog>& shared_ptr_dog_5 = get_shared_ptr_v2();
  std::cout << "ref count : " << shared_ptr_dog_5.use_count() << std::endl; // UNCOMMENT_TO_SEE crash
#endif

  return 0;
}