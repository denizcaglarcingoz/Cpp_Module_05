#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include "AForm.hpp"


class Intern
{
	private:
		const	std::string		target;

	public:
								Intern(void);
								Intern(const Intern& other);
								~Intern();
		
		Intern&					operator=(const Intern& other);

		const std::string&		getTarget() const;

		AForm* 					makeForm(const std::string& formName, const std::string& formTarget) const;
};

std::ostream	&operator<<(std::ostream &o, const Intern& s);

#endif