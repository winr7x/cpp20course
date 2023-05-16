#ifndef SCORES
#define SCORES

#include <iostream>
#include <string>

class Scores{
    public : 
        Scores() = delete;
        Scores(const std::string& course_name)
            : m_course_name{course_name}
        {}

        double& operator[](size_t index);      // NEW_FOR_ME operator[] overloading for modifiable objects like
                                               // Scores math("Math") obj; obj[33] // read/write

        double operator[](size_t index) const; // NEW_FOR_ME operator[] for not modifiable objects like
                                               // const Scores math("Geography") obj; obj[33] // only read

        void print_info()const{
            std::cout << m_course_name << " : [ ";
            for(size_t i{}; i < 20; ++i){
                std::cout << m_scores[i] << " ";
            }
            std::cout << "]" << std::endl;
        }

    private: 
        std::string m_course_name;
        double m_scores[20]{};
};
#endif // SCORES