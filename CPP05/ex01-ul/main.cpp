#include "Bureaucrat.hpp"

int main() {
	// Bureaucrat bureaucrat;
	try {
		Bureaucrat a("Mobile", 2);
		Bureaucrat b("Mabel", 1);
		Bureaucrat c("Momo", 150);

		std::cout << a.getName() << " , bureaucrat grade " << a.getGrade() << std::endl;
		a.increment();
		std::cout << GREEN << a.getName() << " has been increment" << RESET << std::endl;
		std::cout << a.getName() << " , bureaucrat grade " << a.getGrade() << RESET << std::endl;
		a.decrement();
		std::cout << BLUE << a.getName() << " has been decrement" << RESET << std::endl;
		std::cout << a.getName() << " , bureaucrat grade " << a.getGrade() << RESET << std::endl;
		std::cout << "------------------------------------" << std::endl;

		try {
			std::cout << b.getName() << " , bureaucrat grade " << b.getGrade() << std::endl;
			b.decrement();
			std::cout << BLUE << b.getName() << " has been decrement" << RESET << std::endl;
			std::cout << b.getName() << " , bureaucrat grade " << b.getGrade() << RESET << std::endl;
			std::cout << "------------------------------------" << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException &e) {
			std::cerr << MAGENTA << b.getName() << " can not decrement grade because "
				<< RED << e.what() << RESET << std::endl;
		}
		
		try {
			std::cout << c.getName() << " , bureaucrat grade " << c.getGrade() << std::endl;
			c.increment();
			std::cout << GREEN << c.getName() << " has been increment" << RESET << std::endl;
			std::cout << c.getName() << " , bureaucrat grade " << c.getGrade() << RESET << std::endl;
			std::cout << "------------------------------------" << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException &e) {
			std::cerr << MAGENTA << c.getName() << " can not increment grade because "
				<< RED << e.what() << RESET << std::endl;
		}
	}
	catch ( const std::exception &e ) {
		std::cout << RED << "Exception occurred: " << e.what() << RESET << std::endl;
	}
    return 0;
}
