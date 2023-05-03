#include <iostream>

double add(double a , double b){
    return a + b;
}


int main(){
    
    int x{5};
    int y{10};

    int&& result = x + y; // NEW_FOR_ME Extends the lifetime of the temporary result

    double&& outcome = add(10.1,20.2);  // NEW_FOR_ME

    std::cout << "result : " << result << std::endl;
    std::cout << "outcome : " << outcome << std::endl;
   
    return 0;
}