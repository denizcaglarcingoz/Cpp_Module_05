#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
	private:
		const	std::string		target;

	public:
								ShrubberyCreationForm(void);
								ShrubberyCreationForm(const std::string target);
								ShrubberyCreationForm(const ShrubberyCreationForm& other);
								~ShrubberyCreationForm();
		
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

		const std::string&		getTarget() const;

		void 					executeAction() const;
};

std::ostream	&operator<<(std::ostream &o, const ShrubberyCreationForm& s);

#endif