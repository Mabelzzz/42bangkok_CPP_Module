#include "Form.hpp"

Form::Form(): _name(""), _isSigned(false), _gradeToSign(0), _gradeToExecute(0) {
	std::cout << "Form default constructor" << std::endl;
}
Form::Form(const std::string& name, bool& isSigned, const int& gradeToSign, const int& gradeToExecute) : _name(name), _isSigned(isSigned), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "Form constructor" << std::endl;
}

Form::Form(Form const &copy): _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
	std::cout << "Form copy constructor" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor" << std::endl;
}

void Form::beSigned(Bureaucrat &buro) {
	std::cout << buro.getName() << "couldn't sign" << _name << "because" << buro.getGrade() << "is too low" << std::endl;
}

