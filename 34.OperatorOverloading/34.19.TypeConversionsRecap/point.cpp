#include "point.h"
#include "number.h"

Point::Point(double x, double y) : m_x(x) , m_y(y)
{
}

#if CONSTRUCTOR_FROM_NUMBER_ENABLED
Point::Point(const Number& n){
    std::cout << "Point Constructor from Number called: Point(const Number&)" << std::endl;
    m_x = m_y = n.get_wrapped_int();
}
#endif

#if COPY_ASSIGNMENT_OPERATOR_ENABLED
void Point::operator=(const Number& n){
    std::cout << "Point Copy assignment operator from Number called: operator=(const Number&)" << std::endl;
    m_x = m_y = n.get_wrapped_int();    
}
#endif

//Point::Point(const Point& p):Point(p.m_x, p.m_y)
Point::Point(const Point &p)
{
    std::cout << "Copy constructor called to copy point " << p << std::endl;
    if(this != &p){
        m_x = p.m_x;
        m_y = p.m_y;
    }
}
