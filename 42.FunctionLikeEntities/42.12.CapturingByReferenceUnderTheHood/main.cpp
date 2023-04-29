#include <iostream>

int main(){
    int a{7};
    int b {3};
    [[maybe_unused]] int some_var{28};// Not captured by the [=] lambda, so it won't set up a member var  for this
    [[maybe_unused]] double some_other_var{55.5}; // Not captured by the [=] lambda, so it won't set up   a member var for this.
      
    std::cout << "main()'s a : " << a << std::endl;
    //Capturing a few variables by reference
    auto func = [&a,&b] (){
        ++a; // Modifying member vars allowed by default.
        std::cout << "Captured values a:" << a << " b:" << b << '\n';
    };

#if 0 // This code is generated in cppinsights.io
  class __lambda_12_17
  {
    public: 
    inline void operator()() const
    {
      ++a;
      std::cout << "Captured values a:" << a << " b:" << b << '\n';
    }
    
    private: 
    int & a; // NEW_FOR_ME behind the scenes lambda's reference-captured variables turn into functor's field-references
    int & b;
    
    public:
    __lambda_12_17(int & _a, int & _b)
    : a{_a}
    , b{_b}
    {}
    
  };
#endif

    func();
    std::cout << "main()'s a : " << a << std::endl;

    auto func_02 = [&] (){
        ++b;
        std::cout << "Captured values a:" << a << " b:" << b << '\n';
    };

#if 0 // This code is generated in cppinsights.io
  class __lambda_10_19
  {
    public: 
    inline /*constexpr */ void operator()() const
    {
      ++b;
      std::operator<<(std::operator<<(std::cout, "Captured values b:").operator<<(b), '\n');
    }
    
    private: 
    int & b; // NEW_FOR_ME behind the scenes despite of capturing all variables by [&] the generated functor captures only b-variable
             // Because the lambda uses only b-variable in its body
    
    public:
    __lambda_10_19(int & _b)
    : b{_b}
    {}
    
  };
#endif

    func_02();
    std::cout << "main()'s b : " << b << std::endl;

    return 0;
}