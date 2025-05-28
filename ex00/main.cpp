#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat FirstB("Deniz", 1);
        std::cout << FirstB << std::endl;
        FirstB.incrementGrade();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
		Bureaucrat thirdB("Third", 200);
        Bureaucrat SecondB("Second", 150);
       // std::cout << SecondB << std::endl;
		//std::cout << thirdB << std::endl;
        SecondB.decrementGrade();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}