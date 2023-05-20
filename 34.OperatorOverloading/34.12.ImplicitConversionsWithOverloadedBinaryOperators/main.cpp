#include <iostream>

#include "number.h"

int main(){

    Number n1(22);
    std::cout << "n1 : " << n1 << std::endl;

    std::cout << std::endl;

    std::cout << "n1 + 2  : " << (n1 + 2) << std::endl;

    std::cout << std::endl;

#ifdef FREESTANDING_OPERATOR // UNCOMMENT_TO_SEE error: no match for 'operator+' (operand types are 'int' and 'Number')
                             // with member operator+ 1st operand can not be int (can be only Number)
    std::cout << "2 + n1 : " << (2 + n1) << std::endl;

    std::cout << "42 - n1 : " << (42 - n1) << std::endl;
#endif

    return 0;
}