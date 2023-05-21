#include <iostream>
#include "point.h"

int main(){

    Point p1(10,10);
    std::cout << "p1 : " << p1 << std::endl;

    ++p1;
    operator++(p1);

    std::cout << "p1 : " << p1 << std::endl;

#ifdef RETURN_POINT // UNCOMMENT_TO_SEE error: no match for 'operator<<' (operand types are 'std::ostream' and 'void')
    std::cout << ++p1; 
#endif

    return 0;
}