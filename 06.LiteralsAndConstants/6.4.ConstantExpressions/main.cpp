#include <iostream>


int main(){

	constexpr int SOME_LIB_MAJOR_VERSION {1237};
	
	constexpr int eye_count {2};
	
	constexpr double PI {3.14};

    // eye_count = 4; // UNCOMMENT_TO_SEE error: assignment of read-only variable 'eye_count'
	
	std::cout << "eye count : " << eye_count << std::endl;
	std::cout << "PI : " << PI << std::endl;


	//int leg_count {2}; // Non constexpr
	                    // leg_count is not known at compile time
	//constexpr int arm_count{leg_count}; // Error 


	constexpr int room_count{10};
	[[maybe_unused]] constexpr int door_count{room_count};// OK
	
	const int table_count{5};
	[[maybe_unused]] constexpr int chair_count{ table_count * 5};// Works


    static_assert( SOME_LIB_MAJOR_VERSION == 1237); // NEW_FOR_ME check at compile time
	                                                // Constexpr is also used for compile time

   // int age = 5;
   // static_assert( age == 5);

    std::cout << "App doing its thing..." << std::endl;


   
    return 0;
}