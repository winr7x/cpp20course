#include <iostream>



int main(){

    int a{10};
    int b{11};
    [[maybe_unused]] int c{12};
    [[maybe_unused]] int d{13};
    
    //Code1 : Mix by value and by ref
    auto func1 = [a,&b] ([[maybe_unused]] int x,
                         [[maybe_unused]] int y){
        
    };

    //Code2 : All by value, a by reference
    auto func2 = [=,&a] ([[maybe_unused]] int x,
                         [[maybe_unused]] int y){
        
    };

    //Code3 : All by reference, a by value
    auto func3 = [&,a] ([[maybe_unused]] int x,
                        [[maybe_unused]]  int y){
        
    };

    // NEW_FOR_ME Code4 : capture all = and & must always  come first
    // auto func4 = [a,b,&] () {}; // UNCOMMENT_TO_SEE syntax error: '&' was unexpected here

    //Code5 : capture all = and & must always  come first
    // auto func5 = [a,b,=] (int x, int y) {}; // UNCOMMENT_TO_SEE syntax error: '=' was unexpected here


    //Code6 : Can't prefix vars captured  by value with =
    // auto func6 = [=a,=b] (int x, int y) {}; // UNCOMMENT_TO_SEE syntax error: 'a' was unexpected here


    // NEW_FOR_ME Code7 : If you use =, you're no longer allowed to capture any other variable
    // by value, similarly, if you use & , you can't capture any other variable
    // by reference. Some compilers may give a warning, others an error.

    // auto func7 = [=,&b,c] (int x, int y) {}; // UNCOMMENT_TO_SEE '&c' is required when the default capture mode is by copy (=)

    // auto func8 = [&,b,&c] (int x, int y) {}; // UNCOMMENT_TO_SEE '&c' cannot be explicitly captured when the default capture mode is by reference (&)

   
    return 0;
}