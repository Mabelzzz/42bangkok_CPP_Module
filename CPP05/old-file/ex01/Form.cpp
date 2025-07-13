#include "Form.hpp"

Form::Form(): _name(""), _isSigned(false), _gradeToSign(0), _gradeToExecute(0) {
	std::cout << "Form default constructor" << std::endl;
}
Form::Form( const std::string &_name, bool &_isSigned, const int &_gradeToSign, const int &_gradeToExecute): _name(_name), _isSigned(_isSigned), _gradeToSign(_gradeToSign), _gradeToExecute(_gradeToExecute) {
	std::cout << "Form constructor" << std::endl;
}

Form::Form(Form const &copy): _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
	std::cout << "Form copy constructor" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor" << std::endl;
}

// void Form::beSigned(Bureaucrat &buro) {
// 	std::cout << buro.getName() << "couldn't sign" << _name << "because" << buro.getGrade() << "is too low" << std::endl;
// }
// void beSigned(Bureaucrat& buro);


std::string const& Form::getName() const 
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradToExecute() const
{
	return (this->_gradeToExecute);
}