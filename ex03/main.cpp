#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::srand(static_cast<unsigned>(std::time(NULL))); // for seeding at the start just to besure //

    Bureaucrat boss("Deniz", 1);
    Bureaucrat mid ("Mid", 75);
    Intern  internMaker;

    AForm* form1 = internMaker.makeForm("shrubbery creation", "park");
    AForm* form2 = internMaker.makeForm("robotomy request", "Bender");
    AForm* form3 = internMaker.makeForm("presidential pardon", "Arthur");
    AForm* bad = internMaker.makeForm("unknown form", "Nobody"); //bad one naughty boy
    if (!bad)
        std::cout << "Intern couldn’t create an unknown form\n";

    std::cout << "\nUnsigned execute attempts\n";
    try { mid.executeForm(*form1); } catch(...) {}
    try { boss.executeForm(*form2); } catch(...) {}

    std::cout << "\n-- Signing forms --\n";
    mid.signForm(*form1); 
    boss.signForm(*form2);
    boss.signForm(*form3);  

    std::cout << "\n-- Execute signed forms --\n";
    mid.executeForm(*form1);  //this one creates a file don't forget :)
    for(int i=0;i<5;++i) boss.executeForm(*form2);  
    boss.executeForm(*form3);   

    delete form1;
    delete form2;
    delete form3;
    return 0;
}