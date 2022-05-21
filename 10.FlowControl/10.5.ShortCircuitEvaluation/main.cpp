// 74. Short Circuit Evaluations

#include <iostream>

bool car() {
    std::cout << "car function running" << std::endl;
    return false;
}

bool house() {
    std::cout << "house function running" << std::endl;
    return true;
}

bool job() {
    std::cout << "job function running" << std::endl;
    return true;
}

bool spouse() {
    std::cout << "spouse function running" << std::endl;
    return true;
}



int main(int argc, char **argv)
{
    if (car() || house() || job() || spouse()) { // NEW_FOR_ME 'Short Circuit Evaluation' - interrupting calculation when compiler already knows the if result
        std::cout << "I am happy" << std::endl;
    } else {
        std::cout << "I am sad" << std::endl;
    }

    if (car() && house() && job() && spouse()) { // NEW_FOR_ME 'Short Circuit Evaluation' - interrupting calculation when compiler already knows the if result
        std::cout << "I am happy" << std::endl;
    } else {
        std::cout << "I am sad" << std::endl;
    }

    return 0;
}
