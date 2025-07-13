#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm {
    private:
        const std::string _target;

    public:
        ShrubberyCreationForm(const std::string& target);
        ~ShrubberyCreationForm();
        void doAction() const;
};

#endif