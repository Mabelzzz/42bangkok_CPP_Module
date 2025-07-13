#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << GREEN << "[Constructor] ShrubberyCreationForm" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << RED << "[Destructor] ShrubberyCreationForm" << RESET << std::endl;
}

void ShrubberyCreationForm::doAction() const {
    std:: string filename = (this->_target + "_shrubbery").c_str();
    std::ofstream file((this->_target + "_shrubbery").c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open/create file: " << filename << std::endl;
    } else {
        file << "    oxoxoo    ooxoo\n  ooxoxo oo  oxoxooo\n oooo xxoxoo ooo ooox\n oxo o oxoxo  xoxxoxo\n  oxo xooxoooo o ooo\n    ooo\\oo\\  /o/o\n        \\  \\/ /\n         |   /\n         |  |\n         | D|\n         |  |\n         |  |\n  ______/____\\____\n" << std::endl;
        file.close();
    }
}