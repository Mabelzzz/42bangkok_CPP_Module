#include "Fixed.hpp"

Fixed::Fixed() : _fpNum(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	_fpNum = copy._fpNum;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fpNum = rhs._fpNum;
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member funtion called" << std::endl;
	return (_fpNum);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	_fpNum = raw;
}
