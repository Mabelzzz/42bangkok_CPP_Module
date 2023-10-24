#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(float const x, float const ) : _x((Fixed)x), _y((Fixed)y))
{
	// std::cout << "Float constructor called" << std::endl;
}

Point::Point(const Fixed &tmp)
{
	_x = tmp._x;
	_y = tmp._y;
	// std::cout << "Copy constructor called" << std::endl;
}

Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}
