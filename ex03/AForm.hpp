#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
class Bureaucrat;

class AForm {
private:
	const std::string			Name;
	bool						IsSigned;
	const int					GradeToSign;
	const int					GradeToExecute;

public:
								AForm();
								AForm(const std::string& Name, int SignGrade, int ExecGrade);
								AForm(const AForm& copy);
								AForm& operator=(const AForm& other);
	virtual						~AForm();

	const std::string&			getName() const;	
	bool						getIsSigned() const;
	int							getGradeToSign() const;
	int							getGradeToExecute() const;

    void						beSigned(const Bureaucrat& b);


	virtual void executeAction() const = 0;
	void    execute(const Bureaucrat& b) const;
    
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
	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
    };
};

std::ostream&					operator<<(std::ostream& os, const AForm& f);

#endif