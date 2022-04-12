#include "ShrubberyCreationForm.hpp"

static void dprintln(std::string str)
{
	std::cout << DEBUG << "ShrubberyCreationForm: " << str << RESET << std::endl;
}

static void nprintln(std::string str)
{
	std::cout << NOICE << "ShrubberyCreationForm: " << str << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): Form("Shruberry Creation Form", 145, 137), target(target) {
	dprintln("Constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): Form(src.getName(), src.getSignGrade(), src.getExecGrade()), target(src.target) {
	dprintln("Copy constructor called");
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	dprintln("Destructor called");
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &lhs) {
	dprintln("Assignement operator called");
	(void) lhs;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (!this->isSigned())
		throw FormNotSignedException();
	std::ofstream output((this->target + "_shrubbery").c_str());
	if (!output.is_open())
		throw OutputFileException();

	output << "                                                         ." << std::endl;
	output << "                                              .         ;  " << std::endl;
	output << "                 .              .              ;%     ;;   " << std::endl;
	output << "                   ,           ,                :;%  %;   " << std::endl;
	output << "                    :         ;                   :;%;'     .,   " << std::endl;
	output << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
	output << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	output << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
	output << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	output << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
	output << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	output << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
	output << "                      `@%:.  :;%.         ;@@%;'   " << std::endl;
	output << "                        `@%.  `;@%.      ;@@%;         " << std::endl;
	output << "                          `@%%. `@%%    ;@@%;        " << std::endl;
	output << "                            ;@%. :@%%  %@@%;       " << std::endl;
	output << "                              %@bd%%%bd%%:;     " << std::endl;
	output << "                                #@%%%%%:;;" << std::endl;
	output << "                                %@@%%%::;" << std::endl;
	output << "                                %@@@%(o);  . '         " << std::endl;
	output << "                                %@@@o%;:(.,'         " << std::endl;
	output << "                            `.. %@@@o%::;         " << std::endl;
	output << "                               `)@@@o%::;         " << std::endl;
	output << "                                %@@(o)::;        " << std::endl;
	output << "                               .%@@@@%::;         " << std::endl;
	output << "                               ;%@@@@%::;.          " << std::endl;
	output << "                              ;%@@@@%%:;;;. " << std::endl;
	output << "                          ...;%@@@@@%%:;;;;,.." << std::endl;

	output.close();
	nprintln("Created file with a tree in " + this->target + "_shruberry");
}
