#ifndef POINT_H
#define POINT_H
#include <iostream>

class Number;

// #define RETURN_POINT

class Point
{
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
#ifdef RETURN_POINT
	friend Point& operator++(Point& operand);
#else
	friend void operator++(Point& operand);
#endif

public:
	Point() = default;
	Point(double x, double y) : 
		m_x(x), m_y(y){
	}

	~Point() = default;

private: 
	double length() const;   // Function to calculate distance from the point(0,0)

private : 
	double m_x{}; 
	double m_y{}; 
};

inline std::ostream& operator<<(std::ostream& os, const Point& p){
	os << "Point [ x : " << p.m_x << ", y : " << p.m_y << "]";	
	return os;
}

#ifdef RETURN_POINT
	Point&
#else
	void
#endif
 operator++(Point& operand);


#endif // POINT_H
