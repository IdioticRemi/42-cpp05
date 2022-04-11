#include "Bureaucrat.hpp"

static void eprintln(std::string str) {
	std::cout << ERROR << str << RESET << std::endl;
}

int main(void) {
	try {
		Form f("EB110", 0, 1);
	}
	catch (std::exception &e) {
		eprintln(e.what());
	}
	std::cout << std::endl;
	try {
		Form f("EB111", 1, 0);
	}
	catch (std::exception &e) {
		eprintln(e.what());
	}
	std::cout << std::endl;
	try {
		Form f("EB112", 1, 151);
	}
	catch (std::exception &e) {
		eprintln(e.what());
	}
	std::cout << std::endl;
	try {
		Form f("EB113", 151, 1);
	}
	catch (std::exception &e) {
		eprintln(e.what());
	}
	std::cout << std::endl;
	try {
		Bureaucrat john = Bureaucrat("John", 1);
		Form f("EB114", 150, 150);
		std::cout << f << std::endl;
		john.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e) {
		eprintln(e.what());
	}
	std::cout << std::endl;
	try {
		Bureaucrat joe = Bureaucrat("Joe", 10);
		Form f("EB115", 1, 1);
		std::cout << f << std::endl;
		joe.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e) {
		eprintln(e.what());
	}
	return 0;
}
