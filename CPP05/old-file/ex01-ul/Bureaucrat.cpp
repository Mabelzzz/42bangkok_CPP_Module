#include "Bureaucrat.hpp"

// void Bureaucrat::GradeTooHighException::printError() {
// 	std::cout << "Grade is too high" << std::endl;
// }

// void Bureaucrat::GradeTooLowException::printError() {
// 	std::cout << "Grade is too low" << std::endl;
// }

int Bureaucrat::checkGrade() {
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
	else
		return (1);
	return (0);
}

Bureaucrat::Bureaucrat(): _name(""), _grade(0) {
	std::cout << "Bureaucrat default constructor" << std::endl;
	checkGrade();
}

Bureaucrat::Bureaucrat( const std::string &name, const int &grade ): _name(name), _grade(grade) {
	std::cout << "Bureaucrat constructor" << std::endl;
    checkGrade();
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) : _name(copy.getName()), _grade(copy.getGrade())
{
	if (checkGrade())
		std::cout << "Bureaucrat " << _name << " copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor" << std::endl;
}
std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::increment()
{
	_grade += 1;
	checkGrade();
}

void Bureaucrat::decrement()
{
	_grade -= 1;
	checkGrade();
}
// Bureaucrat(Bureaucrat const &copy);
Bureaucrat & Bureaucrat::operator=(Bureaucrat const &copy)
{
	if (this != &copy)
		_grade = copy.getGrade();
	if (checkGrade())
		std::cout << "Bureaucrat " << _name << " copy assignment called" << std::endl;
	return (*this);
}


std::ostream &operator<<( std::ostream& o, const Bureaucrat &buro ) {
	o << buro.getName() << ", bureaucrat grade " << buro.getGrade();
	return o;
}
