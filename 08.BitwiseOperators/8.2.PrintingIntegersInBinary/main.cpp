#include <bitset>
#include <iostream>

int main(){

    unsigned short int data {15};

    std::cout << "data (dec) : " <<std::showbase <<  std::dec << data << std::endl;
    std::cout << "data (oct) : " <<std::showbase <<  std::oct << data << std::endl; // std::showbase for '0'
    std::cout << "data (hex) : " <<std::showbase <<  std::hex << data << std::endl; // std::showbase for '0x'
    std::cout << "data (bin) : " << std::bitset<16>(data) << std::endl; // NEW_FOR_ME way to print out bits of data
   
    return 0;
}