// https://youtu.be/8jLOx1hD3_o?t=13248

#include <iostream>
#include <iomanip>
#include <string>

int main(int argc, char **argv)
{
    using std::cout, std::endl;

    signed int value1 {10};
    signed int value2 {-300};

    cout << "value1 : " << value1 << endl;
    cout << "value2 : " << value2 << endl;
    cout << "sizeof(value1) : " << sizeof(value1) << endl;
    cout << "sizeof(value2) : " << sizeof(value2) << endl;

    unsigned int value3 {4};
    // unsigned int value4 {-5};

    // short. 2 bytes
    short short_var {-32768}; // 2 Bytes
    short int short_int {455}; // 
    signed short signed_short {122}; // 
    signed short int signed_short_int {-456}; // 
    unsigned short int unsigned_short_int {456}; // 

    // int. 4 bytes
    int int_var {55}; // 4 bytes
    signed signed_var {66}; // 
    signed int signed_int {77}; //
    unsigned int unsigned_int {77}; //

    // long. 4 bytes or 8 bytes
    long long_var {88}; // 4 OR 8 Bytes
    long int long_int {33}; // 
    signed long signed_long {44}; // 
    signed long int signed_long_int {44}; // 
    unsigned long int unsigned_long_int {44}; // 

    // long long. 8 bytes
    long long long_long {888}; // 8 Bytes
    long long int long_long_int {999}; // 
    signed long long signed_long_long {444}; // 
    signed long long int signed_long_long_int {1234}; // 
    unsigned long long int unsigned_long_long_int {1234}; // 

    std::cout << "Short variable : " << short_var  << " , size : "
    << sizeof (short) << " bytes" << std::endl;

    std::cout << "Short int : " << short_int << " , size : "
    << sizeof (short int) << " bytes" << std::endl;

    std::cout << "Signed short : " << signed_short << " , size : "
    << sizeof (signed short) << " bytes" << std::endl;

    std::cout << "Signed short int : " << signed_short_int  << " , size : "
    << sizeof (signed short int) << " bytes" << std::endl;

    std::cout << "unsigned short int : " << unsigned_short_int << " , size : "
    << sizeof (unsigned short int) << " bytes" << std::endl;

    std::cout << "---------------------------" << std::endl;

    std::cout << "Int variable : " << int_var << " , size : "
    << sizeof (int) << " bytes" << std::endl;

    std::cout << "Signed variable : " << signed_var  << " , size : "
    << sizeof (signed) << " bytes" << std::endl;

    std::cout << "Signed int : " << signed_int  << " , size : "
    << sizeof (signed int) << " bytes" << std::endl;

    std::cout << "unsigned int : " << unsigned_int << " , size : "
    << sizeof (unsigned int) << " bytes" << std::endl;

    std::cout << "---------------------------" << std::endl;

    std::cout << "Long variable : " << long_var << " , size : "
    << sizeof (long) << " bytes" << std::endl;

    std::cout << "Long int : " << long_int << " , size : "
    << sizeof (long int) << " bytes" << std::endl;

    std::cout << "Signed long : " << signed_long << " , size : "
    << sizeof (signed long) << " bytes" << std::endl;

    std::cout << "Signed long int : " << signed_long_int << " , size : "
    << sizeof (signed long int) << " bytes" << std::endl;

    std::cout << "unsigned long int : " << unsigned_long_int << " , size : "
    << sizeof (unsigned long int) << " bytes" << std::endl;

    std::cout << "---------------------------" << std::endl;

    std::cout << "Long long : " << long_long << " , size : "
    << sizeof (long long) << " bytes" << std::endl;

    std::cout << "Long long int : " << long_long_int << " , size : "
    << sizeof (long long int) << " bytes" << std::endl;

    std::cout << "Signed long long : " << signed_long_long << " , size : "
    << sizeof (signed long long) << " bytes" << std::endl;

    std::cout << "Signed long long int : " << signed_long_long_int << " , size : "
    << sizeof (signed long long int) << " bytes" << std::endl;

    std::cout << "unsigned long long int : " << unsigned_long_long_int << " , size : "
    << sizeof (unsigned long long int) << " bytes" << std::endl;

    return 0;
}
