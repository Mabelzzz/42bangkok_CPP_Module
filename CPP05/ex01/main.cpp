#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat a("Mobile", 5);
        Form f1("PassportForm", 10, 30);
        Form f2("MomoForm", 2, 10);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        a.signForm(f1); // can be signed
        a.signForm(f2); // not signed

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
