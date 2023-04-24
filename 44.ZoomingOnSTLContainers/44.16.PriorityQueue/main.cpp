#include <iostream>
#include <queue>



class Book{
    friend std::ostream& operator<< (std::ostream& out, const Book& operand);
public : 
    Book() = default;
    Book(int year, std::string title) 
        : m_year(year),m_title(title)
        {
        }
        
    bool operator< (const Book & right_operand)const{
        return this->m_year < right_operand.m_year; // original prioriy: bigger year comes to the top.
        //return this->m_year > right_operand.m_year; // reverses original priorities : smaller year comes to the top. 
        //return this->m_title < right_operand.m_title; //Orders by titles in reverse order ( D,C,B,A,...).
    }
    
private : 
    int m_year;
    std::string m_title;
};

std::ostream& operator<< (std::ostream& out, const Book& operand){
    out << "Book [" << operand.m_year << ", " << operand.m_title << "]";
    return out;
}



//template <typename T>
//void print_priority_queue(std::priority_queue<T> p_queue){

template<typename T,
                    typename Container = std::vector<T>, // NEW_FOR_ME default container is vector. deque is also a good choice
                    typename Compare = std::less<typename Container::value_type>>  
void print_priority_queue(std::priority_queue<T,Container,Compare> p_queue){ // NEW_FOR_ME way to print priority queue
    std::cout << "priority queue of elements : [";
    // NEW_FOR_ME p_queue is passed by value so that the original queue is not modified
    while(!p_queue.empty()){
        std::cout << " " << p_queue.top() ; // NEW_FOR_ME top() returns a const reference to the top element and leaves it in container
        p_queue.pop(); // NEW_FOR_ME pop() removes the top element from the container
    }
    std::cout << "]" << std::endl;
}


//template <typename T>
//void clear_queue(std::priority_queue<T>& p_queue){

template<typename T,
                    typename Container = std::vector<T>,
                    typename Compare = std::less<typename Container::value_type>>  
void clear_queue(std::priority_queue<T,Container,Compare> p_queue){ 
    std::cout << "clear_queue() begin. size : " << p_queue.size() << std::endl;
    while(!p_queue.empty()){
        p_queue.pop();
    }
    std::cout << "clear_queue() end. size : " << p_queue.size() << std::endl;
}



int main(){

    //Code1 : Creating  pushing and accessing
    std::priority_queue<int> numbers1; // NEW_FORME The greatest has higher priority in priority queue.
                                       // So 1 is LESS priority than 7. So 7 will be on top()
    
    std::cout << " numbers1 : ";
    print_priority_queue(numbers1);
    
    numbers1.push(10);
    numbers1.push(8);
    numbers1.push(12);
    
    std::cout << " numbers1 : ";
    print_priority_queue(numbers1);
    
    numbers1.push(11);
    numbers1.push(3);
    
    std::cout << " numbers1 : ";
    print_priority_queue(numbers1);
    
    //Acess
    std::cout << " numbers1.top() :  " << numbers1.top() << std::endl;


    //Code2 : Can't through top to modify top element : this is
    //because top() returns  a CONST reference.
    std::cout << std::endl;
    std::cout << "modify top element through top():" << std::endl;
    
    std::cout << " numbers1 (before modification) : ";
    print_priority_queue(numbers1);
    
    // numbers1.top() = 500; // UNCOMMENT_TO_SEE error C3892: 'numbers1': you cannot assign to a variable that is const

    std::cout << " numbers1 (after modification) : ";
    print_priority_queue(numbers1);


    //Code3 : poping : Pops the highest priority element
    std::cout << std::endl;
    std::cout << "poping data : " << std::endl;
    
    std::cout << " numbers1 : ";
    print_priority_queue(numbers1);
    
    numbers1.pop(); // NEW_FOR_ME pop() removes the top element like in stack
    
    std::cout << " numbers1 : ";
    print_priority_queue(numbers1);
    
    numbers1.pop();
    
    std::cout << " numbers1 : ";
    print_priority_queue(numbers1);

    //Code4 : Clearing a priority queue
    std::cout << std::endl;
    std::cout << "clearing a priority queue : " << std::endl;
    
    std::cout << " priority queue initial size : " << numbers1.size() << std::endl;
    std::cout << " numbers1 (before) : ";
    print_priority_queue(numbers1);
    
    clear_queue(numbers1);
    
    std::cout << " priority_queue final size : " << numbers1.size() << std::endl;
    std::cout << " numbers1(after) : ";
    print_priority_queue(numbers1);


    //Code5 : priority_queue of user defined types
    std::cout << std::endl;
    std::cout << "priority queue of user defined type :" << std::endl;
    
    std::priority_queue<Book> books;
    
    //ATTETION : Notice the effects of changing operator< to do a different comparison
    //mechanism and how that affects the priorities perceived by the priority queue
    //this can  be seen in the order the elements are printed in by print_priority_queue : 
    //it starts from the top.
    
    books.push(Book(1921,"Art of War"));
    books.push(Book(2020,"Building Social Media Marketing Strategies"));
    books.push(Book(1990,"Converging Lines of Modern Economy"));
    books.push(Book(1998,"Driving Current Triggered Transistors"));
    
    std::cout << "books : ";
    print_priority_queue(books); // NEW_FOR_ME 2020,"Building Social Media Marketing Strategies" will be on the top
                                 // Because 2020 is greater and has higher priority than 1921
    std::cout << "books size : " << books.size() << std::endl;
    std::cout << "top book : " << books.top() << std::endl;


   //Code6 : specify a custom comparator and/or underlying container
    std::cout << std::endl;
    std::cout << "changing the comparator and underlying container : " << std::endl;
    
    std::priority_queue<int, std::vector<int>, std::less<int> > numbers_01; // Default. // Works with single template parameter functions
    std::priority_queue<int, std::vector<int>, std::greater<int> > numbers_02; // Non default, NEW_FOR_ME compiler doesn't generate correct template instances, we need to be explicit in our print and clear functions
    std::priority_queue<int, std::deque<int>, std::greater<int> > numbers_03;
    auto cmp = [](int left, int right) { return left < right; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> numbers_04(cmp); // Using your own functor // NEW_FOR_ME This uses a different constructor. Let's be honest, this syntax is weird.
  
   
    numbers_01.push(10); numbers_01.push(8); numbers_01.push(12); std::cout << " numbers_01 : "; print_priority_queue(numbers_01);
    numbers_02.push(10); numbers_02.push(8); numbers_02.push(12); std::cout << " numbers_02 : "; print_priority_queue(numbers_02);
    numbers_03.push(10); numbers_03.push(8); numbers_03.push(12); std::cout << " numbers_03 : "; print_priority_queue(numbers_03);
    numbers_04.push(10); numbers_04.push(8); numbers_04.push(12); std::cout << " numbers_04 : "; print_priority_queue(numbers_04);
   
    return 0;
}