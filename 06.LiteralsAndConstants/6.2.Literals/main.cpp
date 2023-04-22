// a literal is stored directly in your program binary code

#include <iostream>

int main(){

   
    //Literal types : u and l combinations for unsigned and long.
    [[maybe_unused]] unsigned char unsigned_char {53u};// 555U would fail because of narrowing
    
    //2 Bytes
    [[maybe_unused]] short short_var {-32768} ; //  No special literal type for short)
    [[maybe_unused]] short int short_int {455} ; //  No special literal type for short
    [[maybe_unused]] signed short signed_short {122}; // No special literal type for short
    [[maybe_unused]] signed short int signed_short_int {-456}; // No special literal type for short
    [[maybe_unused]] unsigned short int unsigned_short_int {5678U };
    
    // 4 Bytes
    [[maybe_unused]] const int int_var {55} ;            //
    [[maybe_unused]] signed signed_var {66};             //
    [[maybe_unused]] signed int signed_int {77};         //
    [[maybe_unused]] unsigned int unsigned_int {555U};       //
    
    
    //4 or 8 Bytes
    [[maybe_unused]] long long_var {88L}; // 4 OR 8 Bytes
    [[maybe_unused]] long int long_int {33L};
    [[maybe_unused]] signed long signed_long {44l};
    [[maybe_unused]] signed long int signed_long_int {44l};
    [[maybe_unused]] unsigned long int unsigned_long_int {555ul};

    [[maybe_unused]] long long long_long {888ll};// 8 Bytes
    [[maybe_unused]] long long int long_long_int {999ll};
    [[maybe_unused]] signed long long signed_long_long {444ll};
    signed long long int signed_long_long_int{1234ll};
    
    //Grouping Numbers : C++14 and onwards
    // NEW_FOR_ME 1500000u == 1500'00'0u && 1500000u  == 1'5'0'0'0'0'0u
    unsigned int prize  {1'500'00'0u};
    std::cout << "The prize is : " << prize << std::endl;

    std::cout << " signed_long_long_int : " << signed_long_long_int << std::endl;
  

    //Narrowing errors
    //Possible narrowing errors are cought by the braced initializer method.
    //Assignment and functional don't catch that.
    // unsigned char distance {555u}; //Error [0~255] // UNCOMMENT_TO_SEE narrowing conversion of '555' from 'unsigned int' to 'unsigned char' [-Wnarrowing]
    // unsigned int game_score {-20}; //Error // UNCOMMENT_TO_SEE narrowing conversion of '-20' from 'int' to 'unsigned int' [-Wnarrowing]

    //std::cout << "game_score : " << game_score << std::endl;

    //With number systems - Hex : prefix with 0x
    unsigned int hex_number{ 0x22BU}; // Dec 555
    int hex_number2 {0x400};// Dec 1024
    std::cout << std::hex <<  "The hex number is : " << hex_number << std::endl;
    std::cout << std::dec <<  "The hex number2 is : " << hex_number2 << std::endl;
    
    //Representing colors with hex
    int black_color {0xffffff};
    std::cout << "Black color is : " << std::dec << black_color << std::endl;


    //Octal literals : prefix with 0
    int octal_number {0777u}; // 511 Dec
    std::cout << "The octal number is : " << octal_number << std::endl;
    //!!BE CAREFUL NOT TO PREFIX YOUR INTEGERS WITH 0 IF YOU MEAN DEC
    int error_octal {055};// This is not 55 in memory , it is 45 dec
    std::cout << "The erronous octal number is : " << error_octal << std::endl;
    
    
    //Binary literals
    unsigned int binary_literal {0b11111111u};// 255 dec
    std::cout << "The binary literal is : " << binary_literal << std::endl;

    // Other literals. This is just an example and we will learn
    // more about  strings as we progress in the course.
    char char_literal {'c'};
    int number_literal {15};
    float fractional_literal {1.5f};
    std::string string_literal {"Hit the road"};
    
    std::cout << "The char literal is : " << char_literal << std::endl;
    std::cout << "The number literal is : " << number_literal << std::endl;
    std::cout << "The fractional literal is : " << fractional_literal << std::endl;
    std::cout << "The string literal is : " << string_literal << std::endl;
   
    return 0;
}