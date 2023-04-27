#include <iostream>
#include "encrypt.h"
#include "decrypt.h"


char encrypt(const char& param){ // Callback function
    return static_cast<char> (param + 3);
}

char decrypt(const char& param){ // Callback function
    return static_cast<char> (param - 3);
}


template <typename Modifier>
std::string & modify(std::string& str_param,
                     Modifier modifier) // NEW_FOR_ME template parameter allows to pass FUNCTION pointers and FUNCTORS
{
     for(size_t i{} ; i < str_param.size() ; ++i){
        str_param[i] = modifier(str_param[i]); // Calling the callback
     }
     return str_param;
}


int main(){

    std::string str {"Hello"};
    
    std::cout << std::endl;
    std::cout << "Modifying string through function pointers : " << std::endl;
    std::cout << "Initial : " << str << std::endl;
    std::cout << "Encrypted : " <<  modify(str,encrypt) << std::endl;   // Call passed FUNCTION inside modify()
    std::cout << "Decrypted : " << modify(str,decrypt) << std::endl;    // Call passed FUNCTION inside modify()

    std::cout << "------" << std::endl;

    //Using functors
    Encrypt encrypt_functor; // Just a class with operator()
    Decrypt decrypt_functor; // Just another class with operator()
    
    std::cout << "encrypt_functor : " << encrypt_functor('A') << std::endl; // Call operator() of Encrypt class-functor. Output: 'D'
    std::cout << "decrypt_functor : " << decrypt_functor('D') << std::endl; // Call operator() of Decrypt class-functor. Output: 'A'


    std::cout << "-----" << std::endl;

    std::cout << std::endl;
    std::cout << "Modifying string through functors : " << std::endl;
    std::cout << "Initial : " << str << std::endl;
    std::cout << "Encrypted : " <<  modify(str,encrypt_functor) << std::endl; // Call passed FUNCTOR inside modify()
    std::cout << "Decrypted : " << modify(str,decrypt_functor) << std::endl; // Call passed FUNCTOR inside modify()

    // both function pointers and functors are called as callback functions

    // both
    //     1) char(*f)(char)
    //     2) class Functor{ char operator()(char){} }
    // are called as callback functions
   
    return 0;
}