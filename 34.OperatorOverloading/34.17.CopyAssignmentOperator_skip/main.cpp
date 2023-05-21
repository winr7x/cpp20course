Too easy

class Point
{
	Point(const Point& p); // Copy constructor

	Point& operator= (const Point& right_operand) { // Point& allows chain assignment point1 = point2 = point3;

		if (this != & right_operand) { // NEW_FOR_ME without this check p_data of right_operand will be delete
			delete p_data;
			p_data = new int(*right_operand.p_data); // without if check deleted object will be used. crash
			m_x =  right_operand.m_x;
			m_y = right_operand.m_y;
		}
		return *this;
	}

private : 
	double m_x{}; 
	double m_y{}; 
	int * p_data;
};

    Point p1(10,10,10);
    Point p2(20,20,20);
    Point p77(3,3,3);

    p1 = p2 = p77;
    p1.operator=(p2).operator=(p77);
    p1.operator=(p2.operator=(p77));

    Point p3(30,30,30);
    Point p4 = p3;       // Copy constructor is called. Not copy assignment operator. Because p4 is initialized here
