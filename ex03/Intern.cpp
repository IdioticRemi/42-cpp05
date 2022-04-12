#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void dprintln(std::string str)
{
	std::cout << DEBUG << "Intern: " << str << RESET << std::endl;
}

static void eprintln(std::string str)
{
	std::cout << ERROR << "Intern: " << str << RESET << std::endl;
}

static void nprintln(std::string str)
{
	std::cout << NOICE << "Intern: " << str << RESET << std::endl;
}

Intern::Intern() {
	dprintln("Constructor called");
}

Intern::Intern(const Intern &src) {
	dprintln("Copy constructor called");
	(void) src;
}

Intern::~Intern() {
	dprintln("Destructor called");
}

Form *Intern::makeForm(const std::string name, const std::string target) const {
	Form *newForm = NULL;
	Intern::formList forms[] = {
			{"shrubbery creation", new ShrubberyCreationForm(target)},
			{"robotomy request", new RobotomyRequestForm(target)},
			{"presidential pardon", new PresidentialPardonForm(target)}
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].name == name)
			newForm = forms[i].form;
		else
			delete forms[i].form;
	}
	if (newForm)
		nprintln("Intern created a " + newForm->getName());
	else
		eprintln("Intern could not find this form type");
	return newForm;
}

Intern &Intern::operator=(const Intern &rhs) {
	dprintln("Assignement operator called");
	(void) rhs;
	return *this;
}
