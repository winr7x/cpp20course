#ifndef POINT_H
#define POINT_H

#include <iostream>

#include "common.h"

class Number;

class Point
{
    friend std::ostream& operator << (std::ostream& out , const Point& point);
public:
    Point() = default;
    Point(double x ,double y);
    Point(const Point& p); // Copy constructor
#if CONSTRUCTOR_FROM_NUMBER_ENABLED
    Point(const Number& n); // Constructor from Number
#endif
    ~Point() = default;
    
    
    //Copy assignment operator
    Point& operator=(const Point& right_operand){
        std::cout << "Copy assignment operator called: Point& operator=(const Point&)" << std::endl;
        if(this!= &right_operand){
             m_x = right_operand.m_x;
             m_y = right_operand.m_y; 
        }
        return *this;
    }

#if COPY_ASSIGNMENT_OPERATOR_ENABLED
    void operator=(const Number& n); // Copy assignment operator for Number
#endif

private: 
    double m_x{0.0};
    double m_y{0.0};
};

inline std::ostream& operator<<(std::ostream& os , const Point& point){
	os << "Point [ x : " << point.m_x << ", y : " << point.m_y << " ]";
	return os;
}


#endif // POINT_H
