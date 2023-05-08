#include <iostream>
#include <concepts>

//This syntax constrains the auto parameters you pass in 
//to comply with the std::integral concept
std::integral auto add (std::integral auto a,std::integral auto b) { // NEW_FOR_ME concepts constraints for return auto, for arguments auto
	return a + b;
}


int main() {
    // add(7.8, 9); // UNCOMMENT_TO_SEE note: the expression 'is_integral_v<_Tp> [with _Tp = double]' evaluated to 'false'

    // std::floating_point auto x = add(5,8); // NEW_FOR_ME concept constraint for auto variable
                                              // UNCOMMENT_TO_SEE note: the expression 'is_floating_point_v<_Tp> [with _Tp = int]' evaluated to 'false'

    std::integral auto y = add(5,8);
    std::cout << "y == " << y << '\n';

    return 0;
}