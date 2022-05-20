// https://youtu.be/8jLOx1hD3_o?t=14042

#include <iostream>
#include <iomanip>
#include <string>

int main(int argc, char **argv)
{
    // Declare and initialize the variables
    float number1 {1.12345678901234567890f};
    double number2 {1.12345678901234567890};
    long double number3 {1.12345678901234567890L};

    // Print out the sizes
    std::cout << "sizeof float : " << sizeof(float) << std::endl;
    std::cout << "sizeof double : " << sizeof(double) << std::endl;
    std::cout << "sizeof long double : " << sizeof(long double) << std::endl;

    std::cout << std::setprecision(20); // Control the precision from std::cout.
    std::cout << "number1 is : " << number1 << std::endl; // 7 digits
    std::cout << "number2 is : " << number2 << std::endl; // 15'ish digits
    std::cout << "number3 is : " << number3 << std::endl; // 7 digits

    // float number4 = 192400023; // UNCOMMENT_FOR_ERROR warning: implicit conversion from 'int' to 'float' changes value from 192400023 to 192400016
                               // NEW_FOR_ME In your case, a float only has about 24 bits of precision. While an int has 32 bits of precision, therefore, some precision is loss by this cast, hence the warning.

    // number4 = number4 + 1;
    // std::cout << "number4 is : " << number4 << std::endl;

    // float number4_2 = 192400023f; // NEW_FOR_ME UNCOMMENT_FOR_ERROR error: invalid digit 'f' in decimal constant

    float number4_3 {192400023.f};
    std::cout << "number4_3 is : " << number4_3 << std::endl;

    double number5 {192400023};
    double number6 {1.92400023e8}; // the same number as above
    double number7 {1.924e8};
    double number8 {0.00000000003498}; // the same number as below
    double number9 {3.49e-11};

    std::cout << "number5 is : " << number5 << std::endl;
    std::cout << "number6 is : " << number6 << std::endl;
    std::cout << "number7 is : " << number7 << std::endl;
    std::cout << "number8 is : " << number8 << std::endl;
    std::cout << "number9 is : " << number9 << std::endl;

    double number10{ 5.6 };
    double number11{}; //Initialized to 0
    double number12{}; //Initialized to 0

    // Infinity
    double result { number10 / number11 }; // NEW_FOR_ME 'inf' value if we use fractional number types (or -inf when negative / 0.0)

    std::cout << number10 << "/" << number11 << "  yields " << result <<  std::endl;
    std::cout << result << " + " << number10 << " yields " << result + number10 << std::endl;

    result = number11 / number12; // NEW_FOR_ME 'nan' (Not A Number) value if we use fractional number types

    std::cout << number11 << "/" << number12 << " = " << result << std::endl;



    return 0;
}
