# ifndef ITER_HPP
# define ITER_HPP

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define RESET		"\033[0m"

#include <cstddef>
#include <iostream>

template <typename T, typename F>
void iter(T* array, const size_t lenth, F func)
{
	for (size_t i = 0; i < lenth; i++)
		func(array[i]);
}

#endif
