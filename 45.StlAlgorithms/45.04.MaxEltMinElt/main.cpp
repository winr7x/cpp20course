#include <algorithm>
#include <iostream>
#include <list>
#include <set>


int main(){

    //std::vector<int> v {3,400,51,6,7,23,56,71};
    //int v[] {3,400,51,6,7,1123,56,71};
    std::list<int> v {3,400,51,6,7,23,56,71};

    //max_elt and min_elt return an iterator to the found elt
    // NEW_FOR_ME std::max_element
    auto result = std::max_element(std::begin(v), std::end(v));
    std::cout << "max element is : " << *result << std::endl;

    // NEW_FOR_ME std::min_element
    result = std::min_element(std::begin(v),std::end(v));
    std::cout << "min element is : " << *result << std::endl;


    std::cout << "----------" << std::endl;

    //Distances : closest and furthest
    int number_to_find {100};
    
    // NEW_FOR_ME lambda stored in variable capturing local variable
    auto distance = [number_to_find](int x, int y){
        return (std::abs(x-number_to_find) < std::abs(y-number_to_find));
    };
    
    //Finding the closest
    // NEW_FOR_ME using min_element to find minimal element in terms of distance to specific number
    result = std::min_element(std::begin(v),std::end(v),distance);
    std::cout << *result << " is closest to " << number_to_find << std::endl;
    
    //Finding the furthest
    // NEW_FOR_ME using max_element to find maximum element in terms of distance to specific number
    result = std::max_element(std::begin(v),std::end(v),distance);
    std::cout << *result << " is furthest from  " << number_to_find << std::endl;


    std::cout << "--------------------------------" << std::endl;

    //Capturing min and max in a pair object with the auto syntax
    // NEW_FOR_ME std::minmax_element returning a pair of iterators
    // structured binding is used
    const auto[near,far] = std::minmax_element(std::begin(v),std::end(v),distance);
    std::cout << *near << " is closest to " << number_to_find << std::endl;
    std::cout << *far << " is furthest from  " << number_to_find << std::endl;
    
    return 0;
}