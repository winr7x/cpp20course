// Too easy

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

struct Sum
{
    void operator()(int n) { sum += n; }
    int sum{0};
};

int main(){

    std::vector<int> nums{3, 4, 2, 8, 15, 267};
    //int nums[]{3, 4, 2, 8, 15, 267};
    //std::set<int> nums{3, 4, 2, 8, 15, 267};

    auto print = [](const int& n) {
        std::cout << " " << n;
    };
 
    //Print each element in the collection : lambda function predicate
    std::for_each(std::begin(nums), std::end(nums), print);                 // lambda stored in variable as predicate. Pass el by value
    std::cout << std::endl;

    std::cout << "---------------------------------" << std::endl;
    
    //Predicate that modifies elements in place
    std::for_each(std::begin(nums), std::end(nums), [](int& n){ n++; });    // lambda function as predicate. Pass el by reference
    
    //Print
    std::for_each(std::begin(nums), std::end(nums), print);
    std::cout << std::endl;
    
    
    std::cout << "---------------------------------" << std::endl;

    //Capturing result through stateful functor that's returned
    // calls Sum::operator() for each number
    Sum s;
    s = std::for_each(std::begin(nums), std::end(nums), s);                 // functor as predicate. Pass el by value
    std::cout << "result : " << s.sum << std::endl;                         // functor accumulates the sum of all elements
    
    std::cout << "---------------------------------" << std::endl;

    //Using a lambda that captures a local variables by ref and modifies it.
    int our_result{0};
    std::for_each(std::begin(nums), std::end(nums),[&our_result](int n) {   // lambda function as predicate. Pass el by value
        our_result += n;                                                    // capture local variable our_result by reference in lambda
    });
    std::cout << "result : " << our_result << std::endl;
    
    return 0;
}