#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << GREEN << "[Constructor] PresidentialPardonForm" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << RED << "[Destructor] PresidentialPardonForm" << RESET << std::endl;
}

void PresidentialPardonForm::doAction() const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}