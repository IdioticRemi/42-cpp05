#ifndef INC_42_CPP05_ROBOTOMYREQUESTFORM_HPP
#define INC_42_CPP05_ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include "Form.hpp"

class RobotomyRequestForm: public Form {
public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	~RobotomyRequestForm();

	void execute(const Bureaucrat &executor) const;

private:
	RobotomyRequestForm &operator=(RobotomyRequestForm &lhs);

	const std::string target;
};

#endif
