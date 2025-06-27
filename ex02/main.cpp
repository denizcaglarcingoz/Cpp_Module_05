#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(static_cast<unsigned>(std::time(NULL))); // for seeding at the start just to besure //

	Bureaucrat boss("Deniz", 1);
	Bureaucrat mid ("Mid", 75);
	Bureaucrat intern("Intern", 146);

	ShrubberyCreationForm f1("garden");
	RobotomyRequestForm     f2("Marvin");
	PresidentialPardonForm  f3("Ford");

	std::cout << "\nUnsigned execute attempts\n";
	try { mid.executeForm(f1); } catch(...) {}
	try { boss.executeForm(f2); } catch(...) {}
	try { intern.executeForm(f3); } catch(...) {}

	std::cout << "\n-- Signing forms --\n";
	intern.signForm(f1); // fails 
	mid.signForm(f1); 
	boss.signForm(f2);
	boss.signForm(f3);  

	std::cout << "\n-- Execute signed forms --\n";
	mid.executeForm(f1);  //this one creates a file don't forget :)
	for(int i=0;i<5;++i) boss.executeForm(f2);  
	boss.executeForm(f3);

	std::cout << "\n-- Grade too low on execute --\n";
	try
	{
		intern.executeForm(f2);
	}
	catch (std::exception& e)
	{
		std::cout << "Caught: " << e.what() << "\n";
	}

	return 0;
}