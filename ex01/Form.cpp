#include "Form.hpp"

static void dprintln(std::string str)
{
	std::cout << DEBUG << "Form: " << str << RESET << std::endl;
}

Form::Form(const std::string &name, int signGrade, int execGrade): name(name), _signed(false), signGrade(signGrade), execGrade(execGrade) {
	dprintln("Constructor called");
	if (signGrade < 1)
		throw GradeTooLowException();
	if (signGrade > 150)
		throw GradeTooLowException();
	if (execGrade < 1)
		throw GradeTooLowException();
	if (execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &src): name(src.name), signGrade(src.signGrade), execGrade(src.execGrade) {
	dprintln("Copy constructor called");
	*this = src;
}

Form &Form::operator=(const Form &lhs) {
	dprintln("Assignement operator called");
	this->_signed = lhs._signed;
	return *this;
}

Form::~Form() {
	dprintln("Destructor called");
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->signGrade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

const std::string &Form::getName() const {
	return this->name;
}

bool Form::isSigned() const {
	return this->_signed;
}

int Form::getSignGrade() const {
	return this->signGrade;
}

int Form::getExecGrade() const {
	return this->execGrade;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "name: " << form.getName() << ", signed: " << form.isSigned()
	   << ", signGrade: " << form.getSignGrade() << ", execGrade: " << form.getExecGrade();
	return os;
}
