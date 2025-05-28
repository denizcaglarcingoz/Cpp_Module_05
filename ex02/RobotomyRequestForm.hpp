#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <ctime> 
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const	std::string		target;

	public:
								RobotomyRequestForm(void);
								RobotomyRequestForm(const std::string target);
								RobotomyRequestForm(const RobotomyRequestForm& other);
								~RobotomyRequestForm();
		
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);

		const std::string&		getTarget() const;

		void 					executeAction() const;
};

std::ostream	&operator<<(std::ostream &o, const RobotomyRequestForm& s);

#endif