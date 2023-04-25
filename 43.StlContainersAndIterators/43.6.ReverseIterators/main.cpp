#include <iostream>
#include <vector>

int main(){

    std::vector<int> numbers {1,2,3,4,5,6,7,8,9,10};

    [[maybe_unused]] auto it_rev = numbers.rbegin();
    // auto notEqual = it_rev != numbers.end(); // UNCOMMENT_TO_SEE error: no match for 'operator!=' (operand types are std::reverse_iterator and std::vector<int>::iterator)

    return 0;
}