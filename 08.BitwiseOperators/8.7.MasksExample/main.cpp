#include <iostream>

const unsigned char mask_bit_0 {0b00000001} ;//Bit0
const unsigned char mask_bit_1 {0b00000010} ;//Bit1
const unsigned char mask_bit_2 {0b00000100} ;//Bit2
const unsigned char mask_bit_3 {0b00001000} ;//Bit3
const unsigned char mask_bit_4 {0b00010000} ;//Bit4
const unsigned char mask_bit_5 {0b00100000} ;//Bit5
const unsigned char mask_bit_6 {0b01000000} ;//Bit6
const unsigned char mask_bit_7 {0b10000000} ;//Bit7

void use_options_v1(unsigned char flags){
   
    std::cout << "bit0 is " << ((flags & mask_bit_0) >> 0 ) << ", do something with it!"<< std::endl;
    std::cout << "bit1 is " << ((flags & mask_bit_1) >> 1 ) <<", do something with it!"<< std::endl;
    std::cout << "bit2 is " << ((flags & mask_bit_2) >> 2 ) <<", do something with it!"<< std::endl;
    std::cout << "bit3 is " << ((flags & mask_bit_3) >> 3 ) <<", do something with it!"<< std::endl;
    std::cout << "bit4 is " << ((flags & mask_bit_4) >> 4 ) <<", do something with it!"<< std::endl;
    std::cout << "bit5 is " << ((flags & mask_bit_5) >> 5 ) <<", do something with it!"<< std::endl;
    std::cout << "bit6 is " << ((flags & mask_bit_6) >> 6 ) <<", do something with it!"<< std::endl;
    std::cout << "bit7 is " << ((flags & mask_bit_7) >> 7 ) <<", do something with it!"<< std::endl;    
}

int main(){
	use_options_v1(mask_bit_0 | mask_bit_7);               // example of using masks

    return 0;
}
