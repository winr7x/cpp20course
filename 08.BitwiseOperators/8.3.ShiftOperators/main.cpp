#include <iostream>
#include <bitset>


int main(){

	unsigned short int value {0xff0u};

	std::cout << "Size of short int " << sizeof(short int) <<  std::endl;//  16 bits
	
    std::cout << "value : " << std::bitset<16>(value)                                     // 0000111111110000
    << ", dec : " << value << std::endl;

    //Shift left by one bit
    value = static_cast<unsigned short int>(value << 1);                                  // 0001111111100000 Shift left by 1 bit (1)
    std::cout << "value : " << std::bitset<16>(value) 
    << ", dec : " << value << std::endl;

    //Shift left by one bit
    value = static_cast<unsigned short int>(value << 1);                                  // 0011111111000000 Shift left by 1 bit (2)
    std::cout << "value : " << std::bitset<16>(value) 
    << ", dec : " << value << std::endl;

    //Shift left by one bit
    value = static_cast<unsigned short int>(value << 1);                                  // 0111111110000000 Shift left by 1 bit (3)
    std::cout << "value : " << std::bitset<16>(value) 
    << ", dec : " << value << std::endl;


    //Shift left by one bit
    value = static_cast<unsigned short int>(value << 1);                                  // 1111111100000000 Shift left by 1 bit (4)
    std::cout << "value : " << std::bitset<16>(value) 
    << ", dec : " << value << std::endl;

    //Shift left by one bit
    value = static_cast<unsigned short int>(value << 1);                                  // 1111111000000000 Shift left by 1 bit (5)
    std::cout << "value : " << std::bitset<16>(value) 
    << ", dec : " << value << std::endl;

    //Shift right by one bit
    value = static_cast<unsigned short int>(value >> 1);                                  // 0111111100000000 Shift RIGHT by 1 bit
    std::cout << "value : " << std::bitset<16>(value) 
    << ", dec : " << value << std::endl;


    //Shift by multiple bits in one go
    //Shift right by four bits 
    value = static_cast<unsigned short int>(value >> 4);                                  // 0000011111110000 Shift RIGHT by 4 bits
    std::cout << "value : " << std::bitset<16>(value) 
    << ", dec : " << value << std::endl;



    //
    std::cout << "value : " << (value >> 1) << std::endl;








   
    return 0;
}