#include <iostream>

#include "point.h"

struct X {
    std::ostream& operator<<(std::ostream& os) const {
        os << "X";
        return os;
    }
};

int main() {
    X() << std::cout << std::endl;                    // NEW_FOR_ME only such inconvenient statement works if we use member operator<< 
    X().operator<<(std::cout).operator<<(std::endl);

    // std::cout << X(); // UNCOMMENT_TO_SEE error: no match for 'operator<<' (operand types are 'std::ostream' and 'X')
                         // This requires out standing operator<<(std::ostream, X)


    Point p1(10,20);
    Point p2(3,4);

    p1.print_info();

    std::cout << '\n';

    std::cout << p1 << ", " << p2 << std::endl;

    return 0;
}