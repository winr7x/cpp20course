#include <iostream>
#include <concepts>

template <typename T>
concept TinyType = requires (T t){
    sizeof(T) <= 4; // NEW_FOR_ME long long is still satisfies this requirement 
                    // This is the simple requirement : Only enforces syntax

    requires sizeof(T) <= 4; // NEW_FOR_ME To check that sizeof(T) is really <= 4 
                             // nested requirements is used: requires { requires }
};

template <TinyType T>
void f([[maybe_unused]] T a){
}

template <typename T>
concept Addable = requires (T a, T b) {
	//noexcept is optional
	{a + b} noexcept -> std::convertible_to<int>; // NEW_FOR_ME compound requirement
	                                              // Checks if a + b is valid syntax, doesn't throw expetions(optional) , and the result
	                                              // is convertible to int(optional)
};


Addable auto add( Addable auto a, Addable auto b){
    return a + b;
}


struct S {
    S operator+(const S &right) const noexcept { // Satisfy {a + b} requirement. See above
                                                 // Satisfy noexcept requirement. See above
        return right;
    }

    operator int() const noexcept { // NEW_FOR_ME Satisfy std::convertible_to<int> requirement. See above
                                    // Satisfy noexcept requirement. See above
        return 7;
    }
};

int main() {
    double x{67};
    double y{56};

    //auto s = x + y;

    auto result  = add(x,y);
    std::cout << "result : " << result << std::endl;
    std::cout << "sizeof(result) : " << sizeof(result) << std::endl;

    [[maybe_unused]] std::string x1{"Hello"};
    [[maybe_unused]] std::string y1{"World"};
    // f(x1); // UNCOMMENT_TO_SEE note: nested requirement '(sizeof (T) <= 4)' is not satisfied

    S s1, s2;
    add(s1, s2);

    return 0;
}