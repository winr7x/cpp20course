#include <iostream>
#include "boxcontainer.h"

// Callback
char encrypt(const char& param){ // Callback function
    return static_cast<char> (param + 3); // NEW_FOR_ME without static_cast undefined behavior in case of char overflow or underflow
    // chatGPT answer:
    // The worst that can happen in this case depends on the specific implementation of the C++ compiler
    // and platform you are using. In general, undefined behavior can result in crashes, data corruption, or other unexpected behavior that 
    // can be difficult to debug and fix.
}

// Callback
char decrypt(const char& param){ // Callback function
    return static_cast<char> (param - 3);
}

std::string & modify(std::string& str_param,
                                        char(* modifier)(const char&))
{
     for(size_t i{} ; i < str_param.size() ; ++i){
        str_param[i] = modifier(str_param[i]); // Calling the callback
     }
     return str_param;
}

//Modifying a BoxContainer of strings
BoxContainer<std::string>& modify(BoxContainer<std::string>& sentence,
                                        char(*modifier) (const char&)){
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
                        bool(*comparator)(const std::string& str1, const std::string& str2)){

    std::string best = sentence.get_item(0);
    for(size_t i{}; i < sentence.size() ; ++i){
            
        if(comparator(sentence.get_item(i),best)){
            best = sentence.get_item(i);
        }
            
    }
         
    return best;
}

// Callback
bool larger_in_size (const std::string& str1, const std::string& str2){
    return str1.size() > str2.size();
}

// Callback
bool greater_lexicographically(const std::string& str1, const std::string& str2){
    return str1 > str2;
}

int main(){

    std::string msg{"Hello"};
    modify(msg,encrypt); // pass encrypt() callback
    std::cout << "'Hello' after applying encrypt() : " << msg << std::endl;

    std::cout << "------\n";

    BoxContainer<std::string> quote;
    quote.add("The");
    quote.add("sky");
    quote.add("is");
    quote.add("blue");
    quote.add("my");
    quote.add("friend");
    std::cout << "Initial : " <<  quote << std::endl;
    std::cout << "Encrypted : " << modify(quote, encrypt) << std::endl; // pass encrypt() callback
    std::cout << "Decrypted : " << modify(quote, decrypt) << std::endl; // pass decrypt() callback


    std::cout << "-------\n";

    std::cout << "larger in size : "           << get_best(quote,larger_in_size) << std::endl;            // pass larger_in_size() callback
    std::cout << "greater lexicographicaly : " << get_best(quote,greater_lexicographically) << std::endl; // pass greater_lexicographically() callback


   
    return 0;
}