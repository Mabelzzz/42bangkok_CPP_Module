#include "Point.hpp"

void	check_inside(bool var)
{
	if (var)
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point isn't inside the triangle" << std::endl;
}

int main( void ) {

	Point	a(1, 1);
	Point	b(3, 5);
	Point	c(5, 1);

	std::cout << "Inside Triangle : ";
	check_inside(bsp(a, b, c, Point(2, 2)));

	std::cout << "Outside Triangle: ";
	check_inside(bsp(a, b, c, Point(5, 5)));

	std::cout << "Lie on ac linear: ";
	check_inside(bsp(a, b, c, Point(3, 1)));
	return 0;
}
