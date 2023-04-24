#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

template<typename T>
void show_collection( const T& collection){
    
    std::cout << " [" ;
    for(const auto& elt : collection){
        std::cout << " " << elt ;
    }
    std::cout << "]" << std::endl;
    
}

template <typename T>
void show_map_collection( const T& collection){
    
    std::cout << " [" ;
    for(const auto& [key,value ]: collection){ // NEW_FOR_ME structured binding
        std::cout << " (" << key << "," << value << ")" ;
    }
    std::cout << "]" << std::endl;
    
}

int main(){

    //std::set<int> collection1 {11,16,2,912,15,6,15,2};
    std::unordered_set<int> collection1 {11,16,2,912,15,6,15,2}; // unordered_set and unordered_map will give you a chance to use to make your code even faster
                                                                 // NEW_FOR_ME underlying data structure is hash table
                                                                 // NEW_FOR_ME gcc stores elements as [ 6 15 912 2 16 11]
                                                                 // MSVC stores elements as [ 11 16 2 912 15 6] as they were in initialization list

    //std::map<int,int> collection2 {{1,11},{0,12},{4,13},{2,14},{3,15}};
    std::unordered_map<int,int> collection2 {{1,11},{0,12},{4,13},{2,14},{3,15}};
    
    
    std::cout << "collection1 : " ;
    show_collection(collection1);
    
    std::cout << "collection2 : ";
    show_map_collection(collection2);
    
    //The operations are mostly similar to std::set and std::map . The details
    //can be checked in your favorite C++ standard library reference manual
    
    
    return 0;
}