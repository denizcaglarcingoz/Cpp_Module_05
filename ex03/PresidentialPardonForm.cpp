#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), target(other.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

const	std::string&	PresidentialPardonForm::getTarget() const
{
	return target;
}

void	PresidentialPardonForm::executeAction() const
{
	std::cout << target << " has been pardoned by Zapyhod Beeblebrox" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm& f)
{
    os << f.getName()
       << " (signed= "   << std::boolalpha << f.getIsSigned()
       << ", signG= "    << f.getGradeToSign()
       << ", execG= "    << f.getGradeToExecute()
       << ", target= "   << f.getTarget()
       << ")";
    return os;
}