#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point
{
	friend Point operator+(const Point& left, const Point& right);
public:
	Point() = default;
	Point(const std::string &name, double x, double y) : 
		m_name(name), m_x(x), m_y(y){
	}
	~Point() = default;

	void print_info(){
		std::cout << "Point [ x : " << m_x << ", y : " << m_y << "]" << std::endl;
	}
private: 
	double length() const;   // Function to calculate distance from the point(0,0)

private :
	std::string m_name;
	double m_x{};
	double m_y{};
};


inline Point operator+(const Point& left, const Point& right) { // NEW_FOR_ME without inline there will be error : multiple definition of `operator+'
                                                                // in point.cpp and main.cpp
																// When you mark a function as "inline", the compiler will replace any calls to that function
																// with the actual body of the function at compile time. This means that there is only one copy of the function in the compiled program, which eliminates the issue of multiple definitions.
	std::cout << "operator+(" << left.m_name << ',' << right.m_name << ")\n";
	return Point("", left.m_x + right.m_x , left.m_y + right.m_y );
}


#endif // POINT_H
