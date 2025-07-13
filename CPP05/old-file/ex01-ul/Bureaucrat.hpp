#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define RESET		"\033[0m"

class Bureaucrat {
	private:
		const std::string	_name;
		int	_grade;

	public:
		Bureaucrat();
		Bureaucrat( const std::string &name, const int &grade );
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat();
		Bureaucrat & operator=(Bureaucrat const &copy);

		std::string getName() const;
		int getGrade() const;
		void increment();
		void decrement();
		int checkGrade();
		void signForm();
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade is too high!";
				}
		};

		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade is too low!";
			}
		};

};

std::ostream &operator<<( std::ostream& os, const Bureaucrat &buro );

#endif

