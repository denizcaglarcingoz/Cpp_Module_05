#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), target(other.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

const	std::string&	ShrubberyCreationForm::getTarget() const
{
	return target;
}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream ofs((target + "_shrubbery").c_str());
	if (!ofs)
		throw std::runtime_error("Cannot open file: " + target + "_shrubbery");

	ofs << "    oxoxooooxoo      \n"
			"  ooxoxooooooooo     \n"
			" ooooxxoxoooooxoo    \n"
			" oxo o oxoxo  xoxo   \n"
			"  oxo xooxoooooxo    \n"
			"    oooo|o|oooo      \n"
			"        |||          \n"
			"        |||          \n"
			"        |||          \n";
	ofs.close();
}

std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& f)
{
	os << f.getName()
		<< " (signed= "		<< std::boolalpha << f.getIsSigned()
		<< ", signG= "		<< f.getGradeToSign()
		<< ", execG= "		<< f.getGradeToExecute()
		<< ", target= "		<< f.getTarget()
		<< ")";
	return os;
}