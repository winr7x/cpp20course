#include <iostream>
#include "point.h"

int main(){


    Point p1(10,10);
    Point p2(20,20);
    Point p3(5,5);

    std::cout << "point1 before: " <<  p1 << std::endl;
    std::cout << "point2 before: " << p2 << std::endl;

    std::cout << "------" << std::endl;

    std::cout << "p1 + p2 : " << (p1 +  p2) << std::endl; // (30,30)
    std::cout << "p2 - p3 : " << (p2 - p3) << std::endl; // (15,15)

    std::cout << "------" << std::endl;

    p1 += p2;
    p2 -= p3;
    
    std::cout << "point1 after: " <<  p1 << std::endl; // (30,30)
    std::cout << "point2 after: " << p2 << std::endl; // (15,15)

    return 0;
}