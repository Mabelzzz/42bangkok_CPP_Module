#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    try {
        if (argc < 2)
            throw PmergeMe::CustomException("Error");

        std::string input;
        for (int i = 1; i < argc; ++i) {
            input += argv[i];
            if (i + 1 < argc) input += " ";
        }

        PmergeMe pm;
        pm.parseInput(input);
        pm.sortAndDisplay();
        return 0;
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
        return 1;
    }
}
