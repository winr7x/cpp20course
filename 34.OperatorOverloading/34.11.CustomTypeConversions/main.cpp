#include <iostream>

#include "number.h"
#include "point.h"

double sum(double a, double b) {
    return a + b;
}
void use_point(const Point& p) {
    std::cout << "Printing the point from use_point func : " << p << std::endl;
}

int main() {

    Number n1(22);
    Number n2(10);

    // auto result = sum (3.0, n2); // UNCOMMENT_TO_SEE error: cannot convert 'Number' to 'double'
    auto result = sum (3.0, static_cast<double>(n2)); // NEW_FOR_ME way to call Number::operator double()
    std::cout << "result : " << result <<  std::endl;

    std::cout << std::endl;

    // use_point(n1); // UNCOMMENT_TO_SEE error: invalid initialization of reference of type 'const Point&' from expression of type 'Number'
    use_point(static_cast<Point>(n1)); // // NEW_FOR_ME way to call Number::operator Point()

    return 0;
}