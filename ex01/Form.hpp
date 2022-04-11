#ifndef CPP05_FORM_HPP
#define CPP05_FORM_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

#define DEBUG "\033[1;36m"
#define NOICE "\033[1;32m"
#define ERROR "\033[1;31m"
#define RESET "\033[0;0m"

class Bureaucrat;

class Form {
public:
	Form(const std::string &name, int signGrade, int execGrade);
	Form(const Form &src);
	virtual ~Form();

	void beSigned(Bureaucrat &bureaucrat);

	const std::string &getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	class GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("grade is too high");
		}
	};
	class GradeTooLowException: public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("grade is too low");
		}
	};
private:
	Form &operator=(const Form &lhs);

	std::string name;
	bool _signed;
	const int signGrade;
	const int execGrade;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
