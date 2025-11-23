#include "MutantStack.hpp"
#include <list>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define GRAY		"\033[0;90m"
# define RESET		"\033[0m"

int main()
{
    std::cout << YELLOW << "--- Testing MutantStack ---" << RESET << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    std::cout << MAGENTA << "Elements in stack: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << RESET << std::endl;

    std::stack<int> s(mstack);

    std::cout << YELLOW << "--- Testing std::list (For comparison) ---" << RESET << std::endl;

    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);

    std::cout << "Top: " << lst.back() << std::endl;
    lst.pop_back();

    std::cout << "Size: " << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();

    ++lit;
    --lit;

    std::cout << MAGENTA << "Elements in list:  ";
    while (lit != lite)
    {
        std::cout << *lit << " ";
        ++lit;
    }
    std::cout << RESET << std::endl;

    return 0;
}
