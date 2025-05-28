#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : Name(""), IsSigned(false), GradeToSign(150), GradeToExecute(150)
{}

Form::Form(const std::string& n, int sG, int eG): Name(n), IsSigned(false), GradeToSign(sG), GradeToExecute(eG)
{
	if (sG < 1 || eG < 1)
		throw GradeTooHighException();
	if (sG > 150 || eG > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& copy): Name(copy.Name), IsSigned(copy.IsSigned), GradeToSign(copy.GradeToSign), GradeToExecute(copy.GradeToExecute)
{}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
	{
        IsSigned = other.IsSigned;
    }
    return *this;
}

Form::~Form()
{}


const		std::string& Form::getName() const { return Name; }
bool		Form::getIsSigned() const { return IsSigned; }
int			Form::getGradeToSign() const { return GradeToSign; }
int			Form::getGradeToExecute() const { return GradeToExecute; }

void		Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > GradeToSign)
		throw GradeTooLowException();
    IsSigned = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{ 
    return "Form grade too high"; 
}
const char*	Form::GradeTooLowException::what() const throw()
{ 
    return "Form grade too low"; 
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << f.getName() << " (sign: " << f.getGradeToSign()
       << ", exec: " << f.getGradeToExecute()
       << ") signed: " << std::boolalpha << f.getIsSigned();
    return os;
}