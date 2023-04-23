// NEW_FOR_ME constinit is to help in avoiding problems with the order of initialization of global variables outside the main function.

#include <iostream>

const int val1 {33};
constexpr int val2{34};
int val3 {35}; // Run time value

// NEW_FOR_ME
constinit int age = 88;          // This is initialized at compile time. NEW_FOR_ME constinit doesn't imply that the variable is const
const constinit int age1 {val1}; // NEW_FOR_ME const and constinit can be combined
constinit int age2 {age1};       // Initializing with age would lead to a compiler error
                                 // age is not const
// constinit int age3 {val3};    // UNCOMMENT_TO_SEE Error : val3 is evaluated at run time
                                 // can't const initialize age3
                           
const constinit double weight {33.33};
// constexpr constinit double scale_factor{3.11}; // UNCOMMENT_TO_SEE NEW_FOR_ME Can't combine constexpr and constinit


int main(){

    // constinit double height{1.72}; // NEW_FOR_ME UNCOMMENT_TO_SEE error: 'constinit' can only be applied to a variable with static or thread storage duration

    std::cout << "age : " << age << std::endl;
    std::cout << "age1 : " << age1 << std::endl;
    std::cout << "age2 : " << age2 << std::endl;
    
    age = 33; // NEW_FOR_ME Can change a const init variable
    std::cout << "age : " << age << std::endl;
    
    // Combining const and constinit
    std::cout << "weight : " << weight << std::endl;
    //weight = 44.44; // Compiler error
    
    return 0;
}