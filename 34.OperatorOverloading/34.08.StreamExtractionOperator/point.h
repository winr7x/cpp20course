#ifndef POINT_H
#define POINT_H
#include <iostream>


class Point
{
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
	friend std::istream& operator>>(std::istream& is, Point& p);
public:
	Point() = default;
	Point(double x, double y) : 
		m_x(x), m_y(y){
	}
	~Point() = default;

	void print_info(){
		std::cout << "Point [ x : " << m_x << ", y : " << m_y << "]" << std::endl;
	}

	/*
	std::ostream& operator<< (std::ostream& os){
		os << "Point [ x : " << m_x << ", y : " << m_y << "]";
		return os;			
	}
	*/

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

inline std::istream& operator>>(std::istream& is, Point& p) { // NEW_FOR_ME operator<< is like operator>> but with std::istream&
    std::cout << "Please type in the coordinates for the point" << std::endl; // NEW_FOR_ME it's ok to print the message in operator>> function
    std::cout << "order [x,y], separated by spaces : ";

	is >> p.m_x >> p.m_y ;

	return is;
}

#endif // POINT_H
