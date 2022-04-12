#include "RobotomyRequestForm.hpp"

static void iprintln(std::string str)
{
	std::cout << GRAYY << "RobotomyRequestForm: " << str << RESET << std::endl;
}

static void dprintln(std::string str)
{
	std::cout << DEBUG << "RobotomyRequestForm: " << str << RESET << std::endl;
}

static void eprintln(std::string str)
{
	std::cout << ERROR << "RobotomyRequestForm: " << str << RESET << std::endl;
}

static void nprintln(std::string str)
{
	std::cout << NOICE << "RobotomyRequestForm: " << str << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): Form("Robotomy Request Form", 72, 45), target(target) {
	dprintln("Constructor called");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): Form(src.getName(), src.getSignGrade(), src.getExecGrade()), target(src.target) {
	dprintln("Copy constructor called");
}

RobotomyRequestForm::~RobotomyRequestForm() {
	dprintln("Destructor called");
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &lhs) {
	dprintln("Assignement operator called");
	(void) lhs;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (!this->isSigned())
		throw FormNotSignedException();
	for (int i = 0; i < 2; i++)
		iprintln("* LOUD DRILLING NOISES *");
	if (std::rand() % 2)
		nprintln("Operation was successful on " + this->target);
	else
		eprintln("Operation was not successful on " + this->target);
}
