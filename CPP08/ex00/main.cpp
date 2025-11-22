#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
    std::cout << YELLOW << "--- Testing with std::vector ---" << RESET << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    try {
		std::cout << "Searching for 30..." << std::endl;
		easyfind(vec, 30);

		std::cout << "Searching for 99..." << std::endl;
		easyfind(vec, 99);
    }
    catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << std::endl;

    std::cout << YELLOW << "--- Testing with std::list ---" << RESET << std::endl;
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try {
		std::cout << "Searching for 3..." << std::endl;
		easyfind(lst, 3);

		std::cout << "Searching for -5..." << std::endl;
        easyfind(lst, -5);
    }
    catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }

    return 0;
}
