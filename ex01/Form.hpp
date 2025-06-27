#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
class Bureaucrat;

class Form {
private:
	const std::string			Name;
	bool						IsSigned;
	const int					GradeToSign;
	const int					GradeToExecute;

public:
								Form();
								Form(const std::string& Name, int SignGrade, int ExecGrade);
								Form(const Form& copy);
								Form& operator=(const Form& other);
								~Form();

	const std::string&			getName() const;	
	bool						getIsSigned() const;
	int							getGradeToSign() const;
	int							getGradeToExecute() const;

	void						beSigned(const Bureaucrat& b);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};
};

std::ostream&					operator<<(std::ostream& os, const Form& f);

#endif