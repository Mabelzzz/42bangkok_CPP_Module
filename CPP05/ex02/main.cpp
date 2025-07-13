#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat high("Momo", 1);
    Bureaucrat mid("Mobye", 70);
    Bureaucrat low("Mobil", 150);

    ShrubberyCreationForm shrub("ant");
    RobotomyRequestForm robo("bird");
    PresidentialPardonForm pardon("cat");

    high.signForm(shrub);
    high.signForm(robo);
    high.signForm(pardon);

    high.executeForm(shrub);
    mid.executeForm(robo);
    low.executeForm(pardon);

    return 0;
}