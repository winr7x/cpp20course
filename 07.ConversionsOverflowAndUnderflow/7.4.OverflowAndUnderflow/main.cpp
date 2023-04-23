#include <iostream>

int main(){

    //Overflow 

    unsigned char data {250};

    ++data;
    std::cout << "data : " << static_cast<int>(data) << std::endl;             // output: 251

    ++data;
    std::cout << "data : " << static_cast<int>(data) << std::endl;             // output: 252

    ++data;
    std::cout << "data : " << static_cast<int>(data) << std::endl;             // output: 253

    ++data;
    std::cout << "data : " << static_cast<int>(data) << std::endl;             // output: 254

    ++data; 
    std::cout << "data : " << std::hex <<  static_cast<int>(data) << std::endl;             // output: ff

    ++data;  // Overflow
    std::cout << "data : " << static_cast<int>(data) << std::endl;             // output: 0 OVERFLOW

    std::cout << std::dec ;


    data = 1;

    --data;
    std::cout << "data : " << static_cast<int>(data) << std::endl;             // output: 0

    --data;
    std::cout << "data : " << static_cast<int>(data) << std::endl;             // output: 255 NEW_FOR_ME UNDERFLOW

   
    return 0;
}