#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150)
{
    std::cout << BLUE << "[Default Constructor] Bureaucrat " << this->_name << " created with grade " << this->_grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    checkValidGrade(grade);
    this->_grade = grade;
    std::cout << BLUE << "[Parameterized Constructor] Bureaucrat " << this->_name << " created with grade " << this->_grade << RESET << std::endl;
} 


Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
    checkValidGrade(other._grade);
    this->_grade = other._grade;
    std::cout << "[Copy Constructor] Copied Bureaucrat " << this->_name << " with grade " << this->_grade << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) 
{
    if (this != &other)
    {
        checkValidGrade(other._grade);
        _grade = other._grade;
        std::cout << "[Assignment Constructor] Assigning Bureaucrat " << other._name << " with grade " << this->_grade << std::endl;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << MAGENTA << "[Destructor] Bureaucrat " << this->_name << " destroyed." << RESET << std::endl;
}

const std::string& Bureaucrat::getName() const
{
    return (this->_name); 
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() 
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm& f) {
    try {
        f.beSigned(*this);
        std::cout << GREEN << _name << " signed " << f.getName() << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << _name << " couldn’t sign " << f.getName()
                  << " because " << e.what() << RESET << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& f) const {
    try {
        f.execute(*this);
        std::cout << BLUE << _name << " executed " << f.getName() << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << _name << " couldn’t execute " << f.getName() << " because " << e.what() << RESET << std::endl;
    }
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

void Bureaucrat::checkValidGrade(int grade) 
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
