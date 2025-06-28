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
		Form( const std::string &_name, bool &_isSigned, const int &_gradeToSign, const int &_gradeToExecute);
		Form(Form const &copy);
		~Form();
		void beSigned(Bureaucrat &buro);
		// signForm();

};

std::ostream &operator<<( std::ostream& os, const Form &form );
#endif
