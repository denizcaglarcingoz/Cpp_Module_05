#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : Name(""), IsSigned(false), GradeToSign(150), GradeToExecute(150)
{
}

AForm::AForm(const std::string& n, int sG, int eG): Name(n), IsSigned(false), GradeToSign(sG), GradeToExecute(eG)
{
	if (sG < 1 || eG < 1)
		throw GradeTooHighException();
	if (sG > 150 || eG > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& copy): Name(copy.Name), IsSigned(copy.IsSigned), GradeToSign(copy.GradeToSign), GradeToExecute(copy.GradeToExecute)
{
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		IsSigned = other.IsSigned;
	}
	return *this;
}
AForm::~AForm()
{
}


const		std::string& AForm::getName() const { return Name; }
bool		AForm::getIsSigned() const { return IsSigned; }
int			AForm::getGradeToSign() const { return GradeToSign; }
int			AForm::getGradeToExecute() const { return GradeToExecute; }

void		AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > GradeToSign)
		throw GradeTooLowException();
	IsSigned = true;
}

void	AForm::execute(const Bureaucrat& b) const
{
	if (!IsSigned)
		throw FormNotSignedException();
	if (b.getGrade() > GradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

const char*	AForm::GradeTooHighException::what() const throw()
{ 
	return "Form grade too high"; 
}
const char*	AForm::GradeTooLowException::what() const throw()
{ 
	return "Form grade too low"; 
}

const char*	AForm::FormNotSignedException::what() const throw()
{ 
	return "The Form is not signed"; 
}


std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << f.getName() << " (sign: " << f.getGradeToSign()
		<< ", exec: " << f.getGradeToExecute()
		<< ") signed: " << std::boolalpha << f.getIsSigned();
	return os;
}