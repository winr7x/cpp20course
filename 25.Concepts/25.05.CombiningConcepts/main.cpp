#include <iostream>
#include <concepts>


template <typename T>
concept TinyType = requires ( T t){
	sizeof(T) <=4; // Simple requirement
	requires sizeof(T) <= 4; // Nested requirement
};


template <typename T>
//requires std::integral<T> || std::floating_point<T> // OR operator
//requires std::integral<T> && TinyType<T>
requires std::integral<T> &&
requires ( T t) {                                    // NEW_FOR_ME define concept right in template-function-definition. 
    sizeof(T) <=4; // Simple requirement             // Avoid this. This is really ugly
    requires sizeof(T) <= 4; // Nested requirement
}
T add(T a, T b){
    return a + b;
}

template <typename T>
requires std::integral<T> || std::floating_point<T> // OR operator
void f([[maybe_unused]] T t){
}

int main(){

    [[maybe_unused]] long long int x{7};
    [[maybe_unused]] long long int y{5};
    // add(x,y); // UNCOMMENT_TO_SEE note: nested requirement '(sizeof (T) <= 4)' is not satisfied

    int x1{7};
    int y1{5};
    add(x1,y1);

    [[maybe_unused]] std::string s;
    // f(s); // UNCOMMENT_TO_SEE note: no operand of the disjunction is satisfied requires std::integral<T> || std::floating_point<T>

    return 0;
}