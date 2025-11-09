#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << BLUE << "[Default Constructor] Serializer created." << RESET << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
	*this = other;
	std::cout << "[Copy Constructor] Copied Serializer." << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	if (this != &other)
	{
		std::cout << "[Assignment Constructor] Assigning Serializer." << std::endl;
	}
	return *this;
}

Serializer::~Serializer()
{
	std::cout << MAGENTA << "[Destructor] Serializer destroyed." << RESET << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

