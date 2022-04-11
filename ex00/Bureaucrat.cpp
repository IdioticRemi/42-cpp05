#include "Bureaucrat.hpp"

static void dprintln(std::string str)
{
	std::cout << DEBUG << str << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
	dprintln("Constructor called");
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): name(src.name), grade(src.grade) {
	dprintln("Copy constructor called");
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &lhs)  {
	dprintln("Assignement operator called");
	this->grade = lhs.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	dprintln("Destructor called");
}

const std::string &Bureaucrat::getName() const {
	return this->name;
}

const int &Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::gradeUp() {
	if (this->grade - 1 < 1)
		throw GradeTooHighException();
	else
		this->grade -= 1;
}

void Bureaucrat::gradeDown() {
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	else
		this->grade += 1;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}