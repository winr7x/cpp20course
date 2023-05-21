#include <iostream>

#include "point.h"

int main() {

    Point p1(10,10);
    std::cout << "p1 : " << p1 << std::endl;

    ++p1;
    p1.operator++(); // NEW_FOR_ME direct operator++() call

    std::cout << "p1 : " << p1 << std::endl;

    // std::cout << ++p1; // NEW_FOR_ME UNCOMMENT_TO_SEE error: no match for 'operator<<' (operand types are 'std::ostream' and 'void')
                       // To fix this error you should return Point& instead of void in operator++

    return 0;
}