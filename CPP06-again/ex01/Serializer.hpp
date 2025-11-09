#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define GRAY		"\033[0;90m"
# define RESET		"\033[0m"

#include <stdint.h>
#include <iostream>
#include "Data.hpp"

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
