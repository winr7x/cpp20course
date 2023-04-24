#include <iostream>
#include <vector>

int main(){

    std::vector<int> numbers {1,2,3,4,5,6,7,8,9,10};
    
    //Trying out reverse iterators
    //auto it = numbers.rbegin(); // A reverse iterator increments backwards from the end.
    std::vector<int>::reverse_iterator it= numbers.rbegin();
    *it = 34;                                                         // 1,2,3,4,5,6,7,8,9,10 --> 1,2,3,4,5,6,7,8,9,34
    std::cout << "Numbers : [";
    while(it != numbers.rend()){                                      // 34 9 8 7 6 5 4 3 2 1
        std::cout << " " << *it ;
        ++it;
    }
    std::cout << "] " << std::endl;

    std::cout << "--------" << std::endl;
    
    // numbers.rbegin() != numbers.end(); // UNCOMMENT_TO_SEE error: no match for 'operator!=' (operand types are 'std::vector<int>::reverse_iterator' and 'std::vector<int>::iterator')

    return 0;
}