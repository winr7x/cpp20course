#include <iostream>
#include <functional>         // NEW_FOR_MEE need for std::function
#include "boxcontainer.h"


//Function pointer
char encrypt(const char& param){
    return static_cast<char> (param + 3);
}

//Functor
class Decrypt
{
public:
    char operator()( const char& param){
         return static_cast<char> (param - 3);
    }
};


//Modifying a BoxContainer of strings
BoxContainer<std::string>& modify(BoxContainer<std::string>& sentence,
                                        //char(*modifier) (const char&)){
                                  std::function<char(const char&)> modifier){
    for(size_t i{}; i < sentence.size() ; ++i){
            
        //Code below relies on get_item() to return a reference
        //Loop through the word modifying each character 
        for(size_t j{} ; j < sentence.get_item(i).size(); ++j){
            sentence.get_item(i)[j] = modifier(sentence.get_item(i)[j]);
        }
    }
    return sentence;
}

std::string get_best (const BoxContainer<std::string>& sentence,
        // bool(*comparator)(const std::string& str1, const std::string& str2)){
        std::function<bool(const std::string& str1,const std::string& str2)> comparator){

    std::string best = sentence.get_item(0);
    for(size_t i{}; i < sentence.size() ; ++i){
            
        if(comparator(sentence.get_item(i),best)){
            best = sentence.get_item(i);
        }
            
    }
        
    return best;
}

//Function pointer
bool larger_in_size (const std::string& str1, const std::string& str2){
    if(str1.size() > str2.size())
        return true;
    else 
        return false;
}


int main(){
#if 0
    BoxContainer< WHAT TYPE TO USE HERE? > func_entities; // NEW_FOR_ME std::function solves problem of universal callback type
                                                          // i.e. storing different-typed callbacks in one container
    func_entities.add(encrypt);
    func_entities.add(decrypt);
    func_entities.add([](const char &param) {
        return static_cast<char>(param + 3);
    });

    for(size_t i{}; i < func_entities.size() ; ++i){
        std::cout << "result " << i << ". D transformed becomes : " << 
                func_entities.get_item(i)('D') << std::endl;
    }
#endif



    //Basic usage of std::function : storing function like entities
    //in a unified way.
    std::function<char(const char&)> my_modifier; // NEW_FOR_ME syntax of std::function

    my_modifier = encrypt; // NEW_FOR_ME assign Function pointer to std::function
    std::cout << "A encrypted becomes : " << my_modifier('A') << std::endl; // D

    Decrypt decrypt;
    my_modifier = decrypt; // NEW_FOR_ME assign Functor to std::function
    std::cout << "D decrypted becomes : " << my_modifier('D') << std::endl;


    my_modifier = [](const char& param){ // NEW_FOR_ME assign Lambda function to std::function
        return static_cast<char> (param + 3);
    };
    std::cout << "A encrypted becomes : " << my_modifier('A') << std::endl; // D



    std::cout << "--------" << std::endl;

    //Storing function like entities in a collection
    std::cout << std::endl;
    std::cout << "Collection of function like entities : " << std::endl;
    
    BoxContainer<std::function<char(const char&)>> func_entities; // NEW_FOR_ME std::function as abstract callback type
    func_entities.add(encrypt); // Function pointer
    func_entities.add(decrypt); // Functor
    func_entities.add([](const char& param){ // Lambda function
        return static_cast<char> (param + 3);
    });
    
    for(size_t i{}; i < func_entities.size() ; ++i){
        std::cout << "result " << i << ". D transformed becomes : " << 
                func_entities.get_item(i)('D') << std::endl;
    }


    std::cout <<"--------" << std::endl;

    //std::function as callback 
    std::cout << std::endl;
    std::cout << "Modifying the quote : " << std::endl;
    BoxContainer<std::string> quote;
    quote.add("The");
    quote.add("sky");
    quote.add("is");
    quote.add("blue");
    quote.add("my");
    quote.add("friend");
    std::cout << "Initial : " <<  quote << std::endl;
    std::cout << "Encrypted : " << modify(quote, encrypt) << std::endl; // NEW_FOR_ME pass free function as std::function argument
    std::cout << "Decrypted : " << modify(quote, decrypt) << std::endl; // pass functor as std::function argument


    std::cout << "----------" << std::endl;

    std::cout << std::endl;
    std::cout << "Gettting the best : " << std::endl;
    
    auto  greater_lexicographically = [](const std::string& str1, const std::string& str2){
    return (str1>str2);
    };
    
    // larger_in_size as std::function<bool(const std::string& str1,const std::string& str2)> argument
    std::cout << "larger in size : " << get_best(quote,larger_in_size) << std::endl; 

    // greater_lexicographically as std::function<bool(const std::string& str1,const std::string& str2)> argument
    std::cout << "greater lexicographicaly : " 
            << get_best(quote,greater_lexicographically) << std::endl;

    return 0;
}