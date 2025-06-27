#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat FirstB("Deniz", 100);
		Form Annex("Annex", 100, 90);
		FirstB.signForm(Annex);
		std::cout << FirstB << " is signed " << (Annex.getIsSigned() ? "true" : "false") << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat thirdB("Third", 150);
		Form Annex("Annex", 100, 90);
		thirdB.signForm(Annex);
		std::cout << thirdB << " is signed " << (Annex.getIsSigned() ? "true" : "false") << std::endl;
		thirdB.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}