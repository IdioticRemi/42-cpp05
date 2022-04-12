#ifndef INC_42_CPP05_PRESIDENTIALPARDONFORM_HPP
#define INC_42_CPP05_PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm: public Form {
public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	~PresidentialPardonForm();

	void execute(const Bureaucrat &executor) const;

private:
	PresidentialPardonForm &operator=(PresidentialPardonForm &lhs);

	const std::string target;
};

#endif
