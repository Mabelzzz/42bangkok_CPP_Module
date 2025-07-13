#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm* form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        Bureaucrat alice("Alice", 1);
        alice.signForm(*form);
        alice.executeForm(*form);
        delete form;
    }

    AForm* badForm = someRandomIntern.makeForm("unknown form", "Nobody");
    if (badForm)
        delete badForm;

    return 0;
}
