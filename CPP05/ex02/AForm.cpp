#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm() :  _name("UnknownAForm"), _isSigned(false), _gradeToSign(100), _gradeToExecute(50)
{
    std::cout << BLUE << "[Default Constructor] AForm " << this->_name 
                  << " created with isSigned = " << (this->_isSigned ? "true" : "false")
                  << ", gradeToSign = " << this->_gradeToSign
                  << ", gradeToExecute = " << this->_gradeToExecute << "."
                  << RESET << std::endl;
}

AForm::AForm(const std::string& name, int sign, int exec)
    : _name(name), _isSigned(false), _gradeToSign(sign), _gradeToExecute(exec)
{
    checkValidGrade(sign, exec);
    std::cout << BLUE << "[Parameterized Constructor] AForm " << this->_name 
                  << " created with isSigned = " << (this->_isSigned ? "true" : "false")
                  << ", gradeToSign = " << this->_gradeToSign
                  << ", gradeToExecute = " << this->_gradeToExecute << "."
                  << RESET << std::endl;
}

AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    checkValidGrade(this->_gradeToSign, this->_gradeToExecute);
    std::cout << "[Copy Constructor] AForm " << this->_name
                  << " created from " << other._name
                  << " with isSigned = " << (this->_isSigned ? "true" : "false")
                  << ", gradeToSign = " << this->_gradeToSign
                  << ", gradeToExecute = " << this->_gradeToExecute << "."
                  << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
        std::cout << "[Assignment Constructor] Assigning AForm " << this->_name 
                      << " copied from " << other._name 
                      << " with isSigned = " << (this->_isSigned ? "true" : "false") << std::endl;
    }
    return *this;
}

AForm::~AForm() {
    std::cout << MAGENTA << "[Destructor] AForm " << this->_name << " destroyed." << RESET << std::endl;

}

const std::string& AForm::getName() const 
{
    return _name;
}

bool AForm::isSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::checkValidGrade(int sign, int exec) 
{
    if (sign < 1 || exec < 1)
        throw GradeTooHighException();
    else if (sign > 150 || exec > 150)
        throw GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    this->_isSigned = true;
}

void AForm::execute(Bureaucrat const& executor) const {
    if (!this->_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    doAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "AForm " << f.getName() << " | Sign grade: "
       << f.getGradeToSign() << " | Exec grade: "
       << f.getGradeToExecute() << " | Signed: "
       << (f.isSigned() ? "Yes" : "No");
    return os;
}
