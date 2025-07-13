#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << GREEN << "[Constructor] RobotomyRequestForm" << RESET << std::endl;
    std::srand(std::time(0));
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << RED << "[Destructor] RobotomyRequestForm" << RESET << std::endl;
}

void RobotomyRequestForm::doAction() const {
    std::cout << YELLOW << "* DRILLING NOISE *" << RESET << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << _target << " robotomy failed!" << std::endl;
}