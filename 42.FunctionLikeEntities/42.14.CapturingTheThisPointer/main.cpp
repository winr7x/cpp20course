#include <iostream>


class Item{
public : 

    Item(int a, int b)
        : m_var1{a}, m_var2{b}
    {}
    void some_member_func(){

        // [](){ auto x = m_var1;        } (); // UNCOMMENT_TO_SEE error 'this' cannot be implicitly captured because no default capture mode has been specified

        // [=](){ auto x = m_var1;       } (); // UNCOMMENT_TO_SEE in GCC: warning: implicit capture of 'this' via '[=]' is deprecated in C++20

        [this](){ // NEW_FOR_ME way to access class field even without this->m_var1
            std::cout << "member vars :" << m_var1 << "," << m_var2 << std::endl;
        } ();

        [&](){ // NEW_FOR_ME way to access class field even without this->m_var1
            std::cout << "member vars :" << m_var1 << "," << m_var2 << std::endl;
        } ();
    };
private : 
    int m_var1;
    int m_var2;
};


int main(){

    Item item1(10,20);
    item1.some_member_func();
    
    return 0;
}