
#include <iostream>
#include "point.h"
class Number
{
    friend std::ostream& operator<<(std::ostream& out , const Number& number);

public:
    Number() = default;
    Number(int value);

    explicit operator double() const { // NEW_FOR_ME way to do custom conversion from Number to double
                                       // m_wrapped_int --> double
                                       // Using explicit in this way allows type conversion only with using static_cast<double>(Number)
                                       // This can help prevent unintentional type conversions and improve the clarity and safety of your code
        std::cout << "Custom conversion from Number to double" << std::endl;
        return (static_cast <double> (m_wrapped_int));
    }

    explicit operator Point() const { // NEW_FOR_ME way to do custom conversion from Number to Point
                                      // m_wrapped_int --> Point (m_wrapped_int, m_wrapped_int)
        std::cout << "Custom conversion from Number to Point" << std::endl;
        return Point(static_cast<double>(m_wrapped_int),
                     static_cast<double>(m_wrapped_int));
    }

private : 
    int m_wrapped_int{0};
};
