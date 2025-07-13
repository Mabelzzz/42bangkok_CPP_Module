#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;


	public:
		Form();
		Form(const std::string& name, bool& isSigned, const int& gradeToSign, const int& gradeToExecute);
		Form(const Form& copy);
		~Form();
		
		// Getter function
		std::string const& getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradToExecute() const;
		
		void beSigned(Bureaucrat& buro);
		void signForm(Bureaucrat& buro);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade is out of bounds!";
				}
		};

		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade is out of bounds!";
			}
		};

};

std::ostream &operator<<( std::ostream& os, const Form& form);
#endif
