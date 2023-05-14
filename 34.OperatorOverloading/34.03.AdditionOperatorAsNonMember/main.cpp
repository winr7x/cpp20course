#include <iostream>
#include "point.h"


int main(){

    Point p1("p1",10,10);
    Point p2("p2",20,20);
    Point p3{p1 + p2}; // opearator+(p1,p2);
    Point p3_2{operator+ (p1,p2)}; // NEW_FOR_ME explicit call operator+

    Point p4{p2 + Point("tmp",5,5)};
    
    p3.print_info();
    p4.print_info();

    (Point("tmp",20,20) + Point("tmp",10,10)).print_info();
    
    return 0;
}