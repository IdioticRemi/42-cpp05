#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void exprintln(std::exception &e)
{
	std::cout << "\033[1;35m" << "Exception: " << e.what() << RESET << std::endl;
}

int main(void) {
	std::srand(std::time(nullptr));
	
	Form *form = NULL;
	Bureaucrat bob("bob", 1);
	Bureaucrat phil("phil", 40);
	Bureaucrat luc("luc", 150);

	try {
		form = new PresidentialPardonForm("28Z");
		bob.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e) {
		exprintln(e);
	}
	std::cout << std::endl;

	try {
		form = new PresidentialPardonForm("28A");
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e) {
		exprintln(e);
	}
	std::cout << std::endl;

	try {
		form = new RobotomyRequestForm("28B");
		bob.signForm(*form);
		phil.executeForm(*form);
		phil.executeForm(*form);
		phil.executeForm(*form);
		phil.executeForm(*form);
		phil.executeForm(*form);
		phil.executeForm(*form);
		phil.executeForm(*form);
		phil.executeForm(*form);
		phil.executeForm(*form);
		phil.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e) {
		exprintln(e);
	}
	std::cout << std::endl;

	try {
		form = new ShrubberyCreationForm("28C");
		bob.signForm(*form);
		phil.executeForm(*form);
		luc.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e) {
		exprintln(e);
	}

	return 0;
}
