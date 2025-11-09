#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << RED << "[Destructor] Base destroyed." << RESET << std::endl;
}

Base* generate()
{
	int random = std::rand() % 3;
	if (random == 0)
	{
		std::cout << GREEN << "Generated instance of A" << RESET << std::endl;
		return new A();
	}
	else if (random == 1)
	{
		std::cout << BLUE << "Generated instance of B" << RESET << std::endl;
		return new B();
	}
	else if (random == 2)
	{
		std::cout << MAGENTA << "Generated instance of C" << RESET << std::endl;
		return new C();
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << BLUE << "Actual type of the object is A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << YELLOW << "Actual type of the object is B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << MAGENTA << "Actual type of the object is C" << RESET << std::endl;
	else
		std::cout << RED << "Unknown type of the object" << RESET << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << BLUE << "Actual type of the object is A" << RESET << std ::endl;
		return ;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Actual type of the object is not A: " << e.what() << RESET << std::endl;
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << YELLOW << "Actual type of the object is B" << RESET << std::endl;
		return ;
	}
	catch(std::exception& e)
	{
		std::cerr << RED << "Actual type of the object is not B: " << e.what() << RESET << std::endl;
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << MAGENTA << "Actual type of the object is C" << RESET << std::endl;
		return ;
	}
	catch(std::exception& e)
	{
		std::cerr << RED << "Actual type of the object is not C: " << e.what() << RESET << std::endl;
	}
}
