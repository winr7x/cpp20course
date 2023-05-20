
#include <iostream>

// #define FREESTANDING_OPERATOR

class Number
{
    friend std::ostream& operator<<(std::ostream& out , const Number& number);

    //Arithmetic operators
#ifdef FREESTANDING_OPERATOR
    friend Number operator+(const Number& left_operand, const Number& right_operand);
#endif
    friend Number operator-(const Number& left_operand, const Number& right_operand);
    friend Number operator*(const Number& left_operand, const Number& right_operand);
    friend Number operator/(const Number& left_operand, const Number& right_operand);
    friend Number operator%(const Number& left_operand, const Number& right_operand);
		
public:
	Number() = default;
	Number(int value );


    explicit operator double()const{
        return (static_cast <double> (m_wrapped_int));
    }

#ifndef FREESTANDING_OPERATOR
    // NEW_FOR_ME with member operator+ implicit conversions won't work for the first operand
    // (number_obj + 2) will compile OK
    // (2 + number_obj) will not compile because 1st operand is this class
    Number operator+(const Number& right) const{
        return Number(m_wrapped_int + right.m_wrapped_int);
    }
#endif
 
    //getter
    int get_wrapped_int() const{
        return m_wrapped_int;
    }
     
    ~Number();
    
private : 
    int m_wrapped_int{0};
};