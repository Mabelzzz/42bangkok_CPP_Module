#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include "Fixed.hpp"

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define GRAY		"\033[0;37m"
# define LRED		"\033[0;91m"
# define BOLD		"\033[1m"
# define RESET		"\033[0m"

class Point {
	private:
		Fixed _x;
		Fixed _y;

	public:
		Point();
		Point(Point const& tmp);
		Point(float const x, float const );
		// Fixed(const int nbr);
		// Fixed(const float nbr);
		~Point();

	bool bsp(Point const a, Point const b, Point const c, Point const point);
};

#endif
