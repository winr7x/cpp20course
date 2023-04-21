#include <iostream>

// NEW_FOR_ME consteval is a C++20 keyword that specifies that a function must be evaluated at compile-time.
// The function must be callable with constant expressions, and its result must be a constant expression
consteval int get_value(){
    return 3;
}

int main() {
    // constexpr is a C++11 keyword that specifies that a function or variable
    // CAN BE evaluated at compile-time if all its inputs are constant expressions
    constexpr int value = get_value();
    std::cout << "value : " << value << std::endl;
    return 0;
}

// consteval specifies that a function MUST BE evaluated at compile-time,
// while constexpr specifies that a function or variable
// CAN BE evaluated at compile-time if its inputs are constant expressions.