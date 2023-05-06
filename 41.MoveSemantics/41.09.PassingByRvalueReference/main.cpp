#include <iostream>
#include "boxcontainer.h"


class Item{
    friend std::ostream& operator<<( std::ostream& out, const Item& operand);
public : 
    Item() : m_data{new int} {
    }
    Item(int value) : m_data{new int(value)}{
    }
    //Copy Members
    Item( const Item& source) : m_data{new int}{
        std::cout << "Item copy constructor copying data..." << std::endl;
        *m_data =(*source.m_data);
    }
    Item& operator=(const Item& right_operand){
        std::cout << "Item copy assignment operator copying data..." << std::endl;
        if (&right_operand != this){
            
            *m_data =(*right_operand.m_data);
        }
        return *this;
    }
    
    //Move Members
    Item( Item&& source){
        std::cout << "Item move constructor moving data..." << std::endl;
        //Steal the pointer
        m_data = source.m_data;
        
        //Reset the source pointer
        source.m_data = nullptr;
    }
    Item& operator=(Item&& right_operand){
        std::cout << "Item move assignment operator moving data..." << std::endl;
        if (&right_operand != this){
            
            //Steal the pointer
            m_data =right_operand.m_data;
            
            //Reset the source pointer
            right_operand.m_data = nullptr;
        }
        return *this;
    }
private : 
    int * m_data{nullptr};
};

std::ostream& operator<<( std::ostream& out, const Item& operand){
    out << "Item : [" << (*operand.m_data) << "]";
    return out;
}


Item get_value(){
    return Item(22);
}


void do_something( Item&& item){
    [[maybe_unused]] Item internal0 = item; // NEW_FOR_ME again, since rvalue has name 'item' in this case, compiler treats 'item'as lvalue
                                            // copy constructor is called here
    Item internal = std::move(item); // Move constructor is called here
    std::cout << "internal : " << internal << std::endl;
}



int main(){

	Item&& rvalue_ref {get_value()};

	Item item0(rvalue_ref); // NEW_FOR_ME Type of arg is Item&& but copy constructor is called here: Item( const Item& )
                            // because compiler treats rvalue with name as lvalue since rvalue has name in this case

    std::cout << "rvalue_ref addr: " << &rvalue_ref << '\n'; // NEW_FOR_ME address of rvalue_rev can be obtained

	Item item1(std::move(rvalue_ref)); // Move constructor is called here

	std::cout << "-------" << std::endl;

    Item&& rvalue_ref2 {get_value()};

    // do_something(rvalue_ref2); // NEW_FOR_ME UNCOMMENT_TO_SEE error: cannot bind rvalue reference of type 'Item&&' to lvalue of type 'Item'
                                  // compiler treats rvalue_ref as lvalue of type 'Item' since rvalue has name in this case

	do_something(std::move(rvalue_ref2));

	std::cout << "-------" << std::endl;

	BoxContainer<Item> items;
	items.add(get_value());

    return 0;
}