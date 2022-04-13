#include "Intern.hpp"

//static void exprintln(std::exception &e)
//{
//	std::cout << "\033[1;35m" << "Exception: " << e.what() << RESET << std::endl;
//}

int	main(void)
{
	std::srand(std::time(nullptr));
	
	Intern		usefulIdiot;
	Bureaucrat	paul("Paul", 3);
	Form		*form;

	form = usefulIdiot.makeForm("this one doesn't exist", "Justin");
	if (form)
		delete form;
	form = usefulIdiot.makeForm("presidential pardon", "Maynard");
	if (form)
		delete form;
	form = usefulIdiot.makeForm("shrubbery creation", "Danny");
	if (form)
		delete form;
	form = usefulIdiot.makeForm("robotomy request", "Adam");
	paul.signForm(*form);
	paul.executeForm(*form);

	delete form;
}