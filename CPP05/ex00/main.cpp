#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a;
		Bureaucrat b("Mobile", 2); // ต้อง throw ตอนสร้าง
		Bureaucrat c("Momo", 1);
		std::cout << GRAY << "------------------------------------------------------------------" << RESET << std::endl;

		std::cout << a << std::endl; 
		a.incrementGrade();
		std::cout << GREEN << a.getName() << " has been increment" << RESET << std::endl;
		std::cout  << a << std::endl; 
		std::cout << GRAY << "------------------------------------" << RESET << std::endl;

		std::cout  << b << std::endl; 
		b.decrementGrade();
		std::cout << YELLOW << b.getName() << " has been decrement" << RESET << std::endl;
		std::cout << b << std::endl; 
		std::cout << GRAY << "------------------------------------" << RESET << std::endl;
	
		std::cout  << c << std::endl; 
		c.incrementGrade();
		std::cout << GREEN << c.getName() << " has been increment" << RESET << std::endl;
		std::cout << c << std::endl; 
		std::cout << GRAY << "------------------------------------" << RESET << std::endl;

		
	}
	// catch (const Bureaucrat::GradeTooLowException &e) {
	// 		std::cerr << "Grade too low: " << e.what() << std::endl;
	// }
	// catch (const Bureaucrat::GradeTooHighException &e) 
	// {
	// 		std::cerr << RED << "Grade too high: " << e.what() << std::endl;
	// }
	catch ( const std::exception &e ) {
		std::cerr << RED << "Exception occurred: " << e.what() << RESET << std::endl;
	}
    return 0;
}
