#include <iostream>

#define FREESTANDING_OPERATOR 1 // NEW_FOR_ME postfix++ can be freestanding operator or as a member

class Point
{
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
#if FREESTANDING_OPERATOR
	friend void operator++(Point& operand);
#endif
	
public:
	Point() = default;
	Point(double x, double y) : 
		m_x(x), m_y(y){
	}

#if !FREESTANDING_OPERATOR
	void operator++() { // ++ Prefix
		++m_x;
		++m_y;
	}

	Point operator++(int) { // Postfix ++
		Point local_point(*this); // We should return previous state before incrementing. local_point is prev state
		++(*this);
		return local_point;
	}
#endif

	~Point() = default;

private : 
	double m_x{}; 
	double m_y{}; 
};

#if FREESTANDING_OPERATOR
void operator++(Point& operand) { // ++ Prefix
	++operand.m_x;
	++operand.m_y;
}

// Postfix ++
Point operator++(Point& operand, int) { // NEW_FOR_ME int is dummy parameter to destinguish postfix from prefix
	Point local_point(operand);         // We should return previous state before incrementing. local_point is prev state
	++operand;
	return local_point;
}
#endif

std::ostream& operator<<(std::ostream& os, const Point& p){
	os << "Point [ x : " << p.m_x << ", y : " << p.m_y << "]";	
	return os;
}

int main(){

    Point p1(10,10);
    std::cout << "p1 : " << p1++ << std::endl;
    std::cout << "p1 : " << p1 << std::endl;
   
    return 0;
}