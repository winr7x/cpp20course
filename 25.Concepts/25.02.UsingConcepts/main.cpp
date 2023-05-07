#include <iostream>
#include <concepts>

template <typename T>
requires std::integral<T> // NEW_FOR_ME Syntax1 of concept
T add_1( T a, T b){
    return a + b;
}

template <std::integral T> // NEW_FOR_ME Syntax2 of concept
T add_2( T a, T b){
    return a + b;
}

auto add_3(std::integral auto a , std::integral auto b){ // NEW_FOR_ME Syntax3 of concept
    return a + b;
}

template <typename T>
T add_4( T a, T b) requires std::integral<T>{ // NEW_FOR_ME Syntax4 of concept
    return a + b;
}


template <typename T>
requires std::floating_point<T>
T subtract_1(T a, T b) {
	return a - b;
}

template <std::floating_point T>
T subtract_2(T a, T b) {
	return a - b;
}

template <typename T>
T subtract_3(T a, T b) requires std::floating_point<T> {
	return a - b;
}

auto subtract_4(std::floating_point auto a, std::floating_point auto b) {
	return a - b;
}

int main(){

   
	char a_0{10};
	char a_1{20};
	
	add_1(a_0, a_1);
	add_2(a_0, a_1);
	add_3(a_0, a_1);
	add_4(a_0, a_1);
	
	int b_0{11};
	int b_1{5};
	add_1(b_0, b_1);
	add_2(b_0, b_1);
	add_3(b_0, b_1);
	add_4(b_0, b_1);

	[[maybe_unused]] double c_0 {11.1};
	[[maybe_unused]] double c_1 {1.9};
	// add_1(c_0,c_1); // UNCOMMENT_TO_SEE 'template<class T> T add(T, T) requires  integral<T>'
	// add_2(c_0,c_1); // UNCOMMENT_TO_SEE 'template<class T> T add(T, T) requires  integral<T>'
	// add_3(c_0,c_1); // UNCOMMENT_TO_SEE 'template<class T> T add(T, T) requires  integral<T>'
	// add_4(c_0,c_1); // UNCOMMENT_TO_SEE 'template<class T> T add(T, T) requires  integral<T>'

    return 0;
}