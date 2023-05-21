Too easy

	Point& operator= (const Point& right_operand) { // NEW_FOR_ME custom copy assignment operator for other type

		if (this != & right_operand) {  // without this check p_data of right_operand will be delete
			delete p_data;
			p_data = new int(*(right_operand.p_data)); // without if check deleted object will be used. crash
			m_x =  right_operand.m_x;
			m_y = right_operand.m_y;
		}

		return *this;
	}