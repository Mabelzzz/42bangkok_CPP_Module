#include "Intern.hpp"

Intern::Intern() {
    std::cout << GREEN << "[Constructor] Intern created" << RESET << std::endl;
}

Intern::Intern(const Intern& other) {
    (void)other;
    std::cout << CYAN << "[Copy Constructor] Intern" << RESET << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    std::cout << YELLOW << "[Assign] Intern" << RESET << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << RED << "[Destructor] Intern" << RESET << std::endl;
}

static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    struct FormPair {
        std::string name;
        AForm* (*creator)(const std::string& target);
    };

    FormPair forms[] = {
        {"shrubbery creation", &createShrubbery},
        {"robotomy request", &createRobotomy},
        {"presidential pardon", &createPardon}
    };

    for (int i = 0; i < 3; ++i) {
        if (forms[i].name == formName) {
            std::cout << BLUE << "Intern creates " << formName << RESET << std::endl;
            return forms[i].creator(target);
        }
    }
    std::cout << RED << "Error: Unknown form name '" << formName << "'" << RESET << std::endl;
    return NULL;
}
