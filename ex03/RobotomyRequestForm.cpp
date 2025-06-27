#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), target(other.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

const	std::string&	RobotomyRequestForm::getTarget() const
{
	return target;
}

void	RobotomyRequestForm::executeAction() const
{
	static bool seeded = false;

	if (seeded == false)
	{
		std::srand(static_cast<unsigned>(std::time(NULL)));
		seeded = true;
	}

	std::cout << "Drill baby Drill!!!!" << std::endl;
	std::cout << "Drill baby Drill!!!!" << std::endl;
	std::cout << "Drill baby Drill!!!!" << std::endl;

	if (std::rand() % 2)
	{
		std::cout << target << " has been robotomized." << std::endl;
	}
	else
	{
		std::cout << target << "robotomy failed." << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& f)
{
	os << f.getName()
		<< " (signed= "		<< std::boolalpha << f.getIsSigned()
		<< ", signG= "		<< f.getGradeToSign()
		<< ", execG= "		<< f.getGradeToExecute()
		<< ", target= "		<< f.getTarget()
		<< ")";
	return os;
}