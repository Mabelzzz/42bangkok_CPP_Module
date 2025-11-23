#include "Span.hpp"
#include <cstdlib> // rand, srand
#include <ctime>

int main()
{
	try {
		Span smallSp = Span(1);
		smallSp.addNumber(42);
		smallSp.shortestSpan();
	}
    catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	Span bigSp(10000);
    std::vector<int> bigData;
    srand(time(NULL));

    for (int i = 0; i < 10000; i++) {
        bigData.push_back(rand());
    }

	try {
        bigSp.addManyNumbers(bigData.begin(), bigData.end());
        std::cout << "Shortest Span: " << bigSp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << bigSp.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW << "--- Test Span Full Exception ---" << RESET << std::endl;
    try {
        Span fullSp(2);
        fullSp.addNumber(1);
        fullSp.addNumber(2);
        fullSp.addNumber(3); // Throw Exception
    }
    catch (const std::exception& e) {
        std::cerr << RED << "Expected Error: " << e.what() << RESET << std::endl;
    }
	return 0;
}
