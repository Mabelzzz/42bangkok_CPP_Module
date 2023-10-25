#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(float const x, float const y) : _x((Fixed)x), _y((Fixed)y)
{
	// std::cout << "Float constructor called" << std::endl;
}

Point::Point(Point const &tmp)
{
	_x = tmp._x;
	_y = tmp._y;
	// std::cout << "Copy constructor called" << std::endl;
}

Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed	Point::getPointX(void) const
{
	return (_x);
}

Fixed	Point::getPointY(void) const
{
	return (_y);
}

Point &	Point::operator=(Point const& rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return *this;
}
