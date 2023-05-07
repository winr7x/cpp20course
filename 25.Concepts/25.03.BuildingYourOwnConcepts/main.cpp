#include <iostream>
#include <type_traits>
#include <concepts>

//Syntax1

template <typename T>
concept MyIntegral_0 = std::is_integral_v<T>;  // NEW_FOR_ME define custom concept syntax
                                               // 'is_intergral' is type trait

MyIntegral_0 auto add( MyIntegral_0 auto a, MyIntegral_0 auto b) {
    return a + b;
}



template <typename T>
concept Multipliable =  requires(T a, T b) { // NEW_FOR_ME define custom concept syntax
    a * b;                                   // Just makes sure the syntax is valid i.e. a * b is compilable
};

template <typename T>
concept Incrementable = requires (T a) {
	a+=1;                                    // concept requires a+=1; ++a; a++ to compile without errors
	++a;
	a++;
};

template <typename T>
concept CustomConcept = requires(T a) {
    a();
    std::cout << a;
};

template <typename T>
requires Incrementable<T>
T add_i (T a, T b){
    return a + b;
}

template <typename T>
requires Multipliable<T>
T add_m(T a, T b) {
    return a + b;
}

template <CustomConcept T>
void f([[maybe_unused]] T a) {
}

struct S {
    void operator()() {
    }
};
std::ostream& operator<<(std::ostream &os, [[maybe_unused]] const S& s) {
    os << "struct S obj";
    return os;
}

int main(){

    double x{6};
    double y{7};

    add_i(x, y);
    add_m(x, y);

    [[maybe_unused]] std::string x1{"Hello"};
    [[maybe_unused]] std::string y1{"World"};
    // add_i(x1, y1); // UNCOMMENT_TO_SEE note: constraints not satisfied requires  Incrementable<T>

    // f(x1); // UNCOMMENT_TO_SEE note: the required expression 'a()' is invalid
    S s;
    f(s);

    std::cout << "Done!" << std::endl;
    
    return 0;
}