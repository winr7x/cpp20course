#include <iostream>
#include <algorithm>
#include <vector>
#include <list> // NEW_FOR_ME std::sort of list will lead to error: no match for 'operator-'. List is not random accessed


class Book{
    friend std::ostream& operator<< (std::ostream& out, const Book& operand);
public : 

    Book(int year, std::string title) 
        : m_year(year),m_title(title)
        {
        }
        
    bool operator< (const Book & right_operand)const{
        return this->m_year < right_operand.m_year;
    }
    
    bool operator> (const Book & right_operand)const{
        return this->m_year > right_operand.m_year;
    }
   
      
    // bool operator==(const Book&  right_operand)const{
    //     return (this->m_year == right_operand.m_year);
    // }
   
    
public : 
    int m_year;
    std::string m_title;
};

std::ostream& operator<< (std::ostream& out, const Book& operand){
    out << "Book [" << operand.m_year << ", " << operand.m_title << "]";
    return out;
}



template<typename T>
void print_collection( const T& collection){
    
    std::cout << " Collection [" ;
    for(const auto& elt : collection){
        std::cout << " " << elt ;
    }
    std::cout << "]" << std::endl;
}



int main(){
    
    //Directly without predicate
    // NEW_FOR_ME std::sort requires collection to be random accessed. std::list sort will fail
    std::vector<int> collection = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3}; 
    
    std::cout << "collection(unsorted) : ";
    print_collection(collection);
    
    std::sort(std::begin(collection),std::end(collection));
    
    std::cout << "collection(sorted) : ";
    print_collection(collection);
    
    
    std::cout << "---------------------------" << std::endl;

    //With custom compare function
    collection = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3}; 
    
    std::cout << "collection(unsorted) : ";
    print_collection(collection);
    
    //std::sort(std::begin(collection),std::end(collection),std::less<int>()); // NEW_FOR_ME std::less<int>() - Function object class for less-than inequality comparison
    //std::sort(std::begin(collection),std::end(collection),std::greater<int>()); // NEW_FOR_ME std::greater<int>() - Function object class for greater-than inequality comparison
    std::sort(std::begin(collection),std::end(collection),[](int x, int y){return x < y;});
    
    std::cout << "collection(sorted) : ";
    print_collection(collection);
    
    
    std::cout << "--------------------------" << std::endl;

    //Sorting collections of custom items
    std::vector<Book> books {Book(1734,"Cooking Food"),
                    Book(2000,"Building Computers"),Book(1995,"Farming for Beginners")};
                    
                    
    std::cout << "books(before sort) : " << std::endl;
    print_collection(books);
    
    //std::sort(std::begin(books),std::end(books));
    //std::sort(std::begin(books),std::end(books),std::less<Book>());
    std::sort(std::begin(books),std::end(books),std::greater<Book>()); // NEW_FOR_ME Will look for Book:: > operator.

    auto cmp = [](const Book& book1, const Book& book2){
        return (book1.m_year < book2.m_year);
    };
  
    std::sort(std::begin(books),std::end(books),cmp); // NEW_FOR_ME std::sort will use lambda instead of Book::operator< sort
    std::sort(std::begin(books),std::end(books)); // NEW_FOR_ME std::sort will use Book::operator< to sort
   
    std::cout << "books(after sort) : " << std::endl;
    print_collection(books);
   
    return 0;
}