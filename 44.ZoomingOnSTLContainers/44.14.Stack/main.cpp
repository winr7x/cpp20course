#include <deque>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

template<typename T, typename Container>
void print_stack(std::stack<T,Container> stack){

// template <typename T>
// void print_stack(std::stack<T> stack){ // UNCOMMENT_TO_SEE error


    //Notice that we're working on a copy here. IMPORTANT
    std::cout << "stack of elements : [";
    while(!stack.empty()){
        T item = stack.top();
        std::cout << " " << item ;
        stack.pop(); // Poping from a copy doesn't affect the original. We're good here.
    }
    std::cout << "]" << std::endl;
}

int main(){
    std::stack<int,std::vector<int>> numbers2; //NEW_FOR_ME Custom underlying sequence container
    std::stack<int,std::list<int>> numbers3;
    std::stack<int,std::deque<int>> numbers4;
    
    std::cout << " numbers2 : ";
    print_stack(numbers2); // Compiler error

    std::cout << " numbers3 : ";
    print_stack(numbers3); // Compiler error

    std::cout << " numbers4 : ";
    print_stack(numbers4); // OK 

    return 0;
}