#ifndef CPP05_BUREAUCRAT_H
#define CPP05_BUREAUCRAT_H

#include <string>
#include <iostream>

#define DEBUG "\033[1;36m"
#define ERROR "\033[1;31m"
#define RESET "\033[0;0m"

class Bureaucrat {
public:
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &src);
	virtual ~Bureaucrat();

	const std::string &getName() const;
	const int &getGrade() const;

	void gradeUp();
	void gradeDown();

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
	Bureaucrat &operator=(const Bureaucrat &lhs);

	const std::string name;
	int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
