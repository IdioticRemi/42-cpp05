#ifndef INC_42_CPP05_INTERN_HPP
#define INC_42_CPP05_INTERN_HPP

#include "Form.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern &src);
	~Intern();

	Form *makeForm(const std::string name, const std::string target) const;

	typedef struct {
		std::string name;
		Form *form;
	} formList;
private:
	Intern &operator=(const Intern &rhs);
};

#endif
