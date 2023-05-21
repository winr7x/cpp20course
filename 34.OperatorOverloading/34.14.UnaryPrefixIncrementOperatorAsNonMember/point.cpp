#include <cmath>
#include "point.h"


double Point::length() const{
    return sqrt(pow(m_x - 0, 2) +  pow(m_y - 0, 2) * 1.0); 
}

// NEW_FOR_ME freestanding prefix ++
#ifdef RETURN_POINT
	Point&
#else
	void
#endif
operator++(Point& operand)
{ 
	++operand.m_x;
	++operand.m_y;
#ifdef RETURN_POINT
	return operand;
#endif
}

