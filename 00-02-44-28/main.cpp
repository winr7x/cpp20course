#include <iostream>

int main(int argc, char **argv)
{
    int age1;
    std::string name;

    std::cout << "Please type your name and age : " << std::endl;

    std::cin >> name;
    std::cin >> age1;

    std::cout << "Hello " << name << " you are " << age1 << " years old!" << std::endl;

    return 0;
}