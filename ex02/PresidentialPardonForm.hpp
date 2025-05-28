#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const	std::string		target;

	public:
								PresidentialPardonForm(void);
								PresidentialPardonForm(const std::string target);
								PresidentialPardonForm(const PresidentialPardonForm& other);
								~PresidentialPardonForm();
		
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

		const std::string&		getTarget() const;

		void 					executeAction() const;

};

std::ostream	&operator<<(std::ostream &o, const PresidentialPardonForm& s);

#endif