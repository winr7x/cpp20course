#include <iostream>

int main(){

    int a{7};
    int b {3};
    [[maybe_unused]] int some_var{28};// Not captured by the [=] lambda, so it won't set up a member var for this
    [[maybe_unused]] double some_other_var{55.5}; // Not captured by the [=] lambda, so it won't set up a member var for this.

    auto func = [a, b] (int c, int d) {
        std::cout << "\nCaptured values : a:" << a << " b:" << b << std::endl;
        std::cout <<      "Parameters : c:" << c << " d:" << d << std::endl;
        // a = 777; // NEW_FOR_ME UNCOMMENT_TO_SEE  error: 'a': a by copy capture cannot be modified in a non-mutable lambda
    };
    func(10,20);

#if 0 // This code was generated in cppinsights.io:
  class __lambda_10_17
  {
    public: 
    inline void operator()(int c, int d) const // NEW_FOR_ME behind the scenes compiler generates functor with operator()() CONST.
                                               // So any modifications to captured a and b are impossible
    {
        std::cout << "\nCaptured values : a:" << a << " b:" << b << std::endl;
        std::cout <<      "Parameters : c:" << c << " d:" << d << std::endl;
    }
    
    private: 
    int a; // NEW_FOR_ME behind the scenes captured a and b are converted to Functor's member variables
    int b;
    
    public:
    __lambda_10_17(int & _a, int & _b) // NEW_FOR_ME a,b are passed by reference, but class' members a,b are not references!
                                       // So, the main's a,b stay untouched
    : a{_a}
    , b{_b}
    {}
  };
  __lambda_10_17 func = __lambda_10_17{a, b};
  func.operator()(10, 20);
#endif

    auto func_02 = [=] (int c, int d) { // NEW_FOR_ME [=] captures all variables before lambda
        std::cout << "\nCaptured value : b:" << b << std::endl;
        std::cout <<      "Parameters : c:" << c << " d:" << d << std::endl;
    };
    func_02(10,20);

#if 0 // This code was generated in cppinsights.io:
  class __lambda_10_20
  {
    public: 
    inline void operator()(int c, int d) const
    {
        std::cout << "\nCaptured value : b:" << b << std::endl;
        std::cout <<      "Parameters : c:" << c << " d:" << d << std::endl;
    }
    
    private: 
    int b; // NEW_FOR_ME behind the scenes despite of capturing all variables by [=] the generated functor captures only b-variable
           // Because the lambda uses only b-variable in its body
    
    public:
    __lambda_10_20(int & _b)
    : b{_b}
    {}
    
  };
  
  __lambda_10_20 func_02 = __lambda_10_20{b};
  func_02.operator()(10, 20);
#endif

    auto func_03 = [b] (int c, int d) mutable { // NEW_FOR_ME mutable lambda allows to modify captured values
        std::cout << "\nCaptured value : b:" << b << std::endl;
        std::cout <<      "Parameters : c:" << c << " d:" << d << std::endl;
        b = 777;
    };
    std::cout << "b in main() is equal " << b << '\n';
    func_03(10,20); // NEW_FOR_ME since behind the scenes mutable lambda is converted to functor with mutable b class-member,
                    // after this call lambda will remember new value 777
    std::cout << "b in main() is equal " << b << '\n'; // But main()'s b stays untouched
    func_03(10,20);

#if 0
  class __lambda_10_20
  {
    public: 
    inline void operator()(int c, int d) // NEW_FOR_ME behind the scenes mutable lambda is converted to functor's NON-CONST operator()()
                                         // that can modify b-class-member
    {
        std::cout << "\nCaptured value : b:" << b << std::endl;
        std::cout <<      "Parameters : c:" << c << " d:" << d << std::endl;
        b = 777;
    }
    
    private: 
    int b;
    
    public:
    __lambda_10_20(int & _b)
    : b{_b}
    {}
  };
#endif

    return 0;
}