#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
class AForm;

class Bureaucrat
{
private:
	const std::string		name;
	int						grade;

public:
							Bureaucrat();
							Bureaucrat(const std::string& name, int grade);
							Bureaucrat(const Bureaucrat &bCopy);

							~Bureaucrat();

	Bureaucrat&				operator=(const Bureaucrat& other);

	const std::string&		getName() const;
	int						getGrade() const;

	void					incrementGrade();
	void					decrementGrade();

	void 					signForm(AForm& form);
	void					executeForm(const AForm& form);

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
};

std::ostream& 				operator<<(std::ostream& os, const Bureaucrat& b);

#endif