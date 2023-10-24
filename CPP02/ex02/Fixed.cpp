#include "Fixed.hpp"

Fixed::Fixed() : _fpNum(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const nbr) : _fpNum( nbr << bits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const nbr) : _fpNum((int)roundf(nbr * (1 << bits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	_fpNum = copy._fpNum;
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (_fpNum);
}

void	Fixed::setRawBits(int const raw)
{
	_fpNum = raw;
}

float	Fixed::toFloat(void) const
{
	return (getRawBits() / (float)(1 << bits));
}

int	Fixed::toInt(void) const
{
	return (getRawBits()>>bits);
}

Fixed&	Fixed::operator=(Fixed const& rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fpNum = rhs._fpNum;
	return *this;
}

Fixed Fixed::operator+(Fixed const& rhs)
{
	return (Fixed)(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const& rhs)
{
	return (Fixed)(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const& rhs)
{
	return (Fixed)(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const& rhs)
{
	return (Fixed)(this->toFloat() / rhs.toFloat());
}

Fixed&	Fixed::operator++(void)
{
	this->_fpNum += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	tmp._fpNum = this->_fpNum;
	this->_fpNum += 1;
	return (tmp);
}

Fixed&	Fixed::operator--(void)
{
	this->_fpNum -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	tmp._fpNum = this->_fpNum;
	this->_fpNum -= 1;
	return (tmp);
}

bool Fixed::operator>(Fixed const &rhs)
{
	return (getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const &rhs)
{
	return (getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs)
{
	return (getRawBits() >= rhs.getRawBits());
}
bool Fixed::operator<=(Fixed const &rhs)
{
	return (getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const &rhs)
{
	return (getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const &rhs)
{
	return (getRawBits() != rhs.getRawBits());
}

std::ostream & operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}


Fixed & Fixed::min( Fixed &a, Fixed &b ) {
	if ( a.getRawBits() < b.getRawBits() )
		return a;
	return b;
}

const Fixed & Fixed::min(Fixed const &a, Fixed const &b) {
	if ( a.getRawBits() < b.getRawBits() )
		return a;
	return b;
}

Fixed & Fixed::max(Fixed &a, Fixed &b) {
	if ( a.getRawBits() > b.getRawBits() )
		return a;
	return b;
}

const Fixed & Fixed::max(Fixed const &a, Fixed const &b)
{
	if ( a.getRawBits() > b.getRawBits() )
		return a;
	return b;
}


