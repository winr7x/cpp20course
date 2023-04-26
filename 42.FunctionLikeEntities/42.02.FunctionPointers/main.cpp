#include <iostream>

double add(double a, double b){
    return a+b;
}

int main(){

    [[maybe_unused]] double (*f_ptr_01) (double, double)  = &add;
    [[maybe_unused]] double (*f_ptr_02) (double,double) = add;

                     double (*f_ptr_03) (double,double) {&add};
                     double (*f_ptr_04) (double,double) {add};

    [[maybe_unused]] auto f_ptr_05 = &add;
    [[maybe_unused]] auto f_ptr_06 = add;

                     auto *f_ptr_07 = &add; // NEW_FOR_ME auto f_ptr and auto *f_ptr do the same
                     auto *f_ptr_08 = add;

    //Things gone wroong
    [[maybe_unused]] double (*f_ptr) (double , double) = nullptr;


    std::cout << "add(10,30) : " << f_ptr_03(10,30) << std::endl;
    std::cout << "add(10,30) : " << f_ptr_04(10,30) << std::endl;
    std::cout << "add(10,30) : " << f_ptr_07(10,30) << std::endl;
    std::cout << "add(10,30) : " << f_ptr_08(10,30) << std::endl;
    
    return 0;
}