 #include <iostream>
#include "point.h"
#include "number.h"

void do_something_with_point(const Point& p){
    std::cout << "point : " << p << std::endl;
}


int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
	Point point(10,10);
    Number number(22);

    point = number; // NEW_FOR_ME priority the compiler uses for the assignment point = number:
    // .(1) Copy assignment operator                       Point::operator=(const Number&)
                                                           // NEW_FOF_ME WITHOUT copy assignment operator and WITH -pedantic option 
                                                           // ambiguous conversion compile error from 'Number' to 'const Point' arises
                                                           // ambiguity arises between "Number::operator Point() const" and "Point::Point(const Number&)"
                                                           // comment CMakeLists.txt::rooster_remove_executable_pedantic_option() to see

    // .(2) Constructor taking in a Number                 Point::Point(const Number&)       set common.h::COPY_ASSIGNMENT_OPERATOR_ENABLED 0 to see
    // .(3) Type conversion operator : Number -> Point     Number::operator Point() const    set additionally common.h::CONSTRUCTOR_FROM_NUMBER_ENABLED 0 to see

    std::cout << std::endl;

    do_something_with_point(number); // NEW_FOR_ME priority the compiler uses for the Number to Point passing
    // Copy assignment operator IS NOT involved at all
    // .(1) Constructor                                    Point::Point(const Number&)
    // .(2) Type conversion operator                       Number::operator Point() const    set common.h::CONSTRUCTOR_FROM_NUMBER_ENABLED 0 to see
	
	return 0;
}
