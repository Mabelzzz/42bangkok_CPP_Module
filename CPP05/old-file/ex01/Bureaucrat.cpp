#include "Bureaucrat.hpp"

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

Bureaucrat::Bureaucrat(const std::string& name, const int& grade ): _name(name), _grade(grade) {
	std::cout << "Bureaucrat constructor" << std::endl;
    checkGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy.getName()), _grade(copy.getGrade())
{
	if (checkGrade())
		std::cout << "Bureaucrat " << _name << " copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
		this->_grade = copy.getGrade();
	if (checkGrade())
		std::cout << "Bureaucrat " << this->_name << " copy assignment called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	this->_grade -= 1;
	checkGrade();
}

void Bureaucrat::decrementGrade()
{
	this->_grade += 1;
	checkGrade();
}

void Bureaucrat::signForm(Form& f)
{
	if (f.getIsSigned())
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	else
		std::cout << this->_name << " couldn't sign " << f.getName() << " because "
}

std::ostream &operator<<( std::ostream& o, const Bureaucrat& buro ) 
{
	o << buro.getName() << ", bureaucrat grade " << buro.getGrade();
	return o;
}
