#include "PresidentialPardonForm.hpp"

static void dprintln(std::string str)
{
	std::cout << DEBUG << "PresidentialPardonForm: " << str << RESET << std::endl;
}

static void nprintln(std::string str)
{
	std::cout << NOICE << "PresidentialPardonForm: " << str << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): Form("Presidential Pardon Form", 25, 5), target(target) {
	dprintln("Constructor called");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): Form(src.getName(), src.getSignGrade(), src.getExecGrade()), target(src.target) {
	dprintln("Copy constructor called");
}

PresidentialPardonForm::~PresidentialPardonForm() {
	dprintln("Destructor called");
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &lhs) {
	dprintln("Assignement operator called");
	(void) lhs;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (!this->isSigned())
		throw FormNotSignedException();
	nprintln(this->target + " has been pardonned by Zaphod Beeblebrox");
}
