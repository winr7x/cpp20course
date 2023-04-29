#include <iostream>

int main(){

    [[maybe_unused]] int result = [] (int x, int y) -> int { return x + y; }(7,3); // NEW_FOR_ME lambda specifying return type

/* NEW_FOR_ME behind the scenes lambda is converted to functor: class with operator()() defined:
    class __lambda_5_11
    {
        public: 
        inline int operator()(double a, double b) const
        {
        return static_cast<int>(a + b);
        }
    }
    
    int x = __lambda_5_11.operator()(10, 20);
    // NEW_FOR_ME to see this code-behind-the-scenes of lambda cppinsights.io was used
*/



    //Auto type deduction can help deduce the type of the generated lambda function
    //We don't have access to that in our C++ code.
    [[maybe_unused]] auto func = [] (int x, int y) -> int { return x + y; };
    // int i = func; // NEW_FOR_ME UNCOMMENT_TO_SEE cannot convert from 'main::<lambda_2>' to 'int'

    [[maybe_unused]] auto func_2 = [] (int x, double y, std::string z) -> char { return static_cast<char>(x + y + z.size()); };
    // int i = func_2; // UNCOMMENT_TO_SEE cannot convert from 'main::<lambda_3>' to 'int'


    return 0;
}