#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{}

static AForm* makeShrubbery(const std::string& t)
{
	return new ShrubberyCreationForm(t);
}
static AForm* makeRobotomy (const std::string& t)
{
	return new RobotomyRequestForm(t);
}
static AForm* makePardon  (const std::string& t)
{
	return new PresidentialPardonForm(t);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget) const
{
	struct Pair
	{
		const char* formName;
		AForm*(*formType)(const std::string&);
	};

	Pair table[3]=
	{
		{"shrubbery creation", makeShrubbery},
		{"robotomy request",  makeRobotomy },
		{"presidential pardon",makePardon  }
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == table[i].formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return table[i].formType(formTarget);
		}
	}
	std::cout << "Error: Intern couldn’t create \"" << formName << "\"" << std::endl;
	return 0;
}