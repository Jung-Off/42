
#include "Fixed.hpp"

Fixed::Fixed() : _FixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	(*this) = fixed;	// operator=
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &fixed)						
		_FixedPoint = fixed.getRawBits();	
	return (*this);							
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return(_FixedPoint);
}

void Fixed::setRawBits(const int raw)
{
	_FixedPoint = raw;
}

Fixed::Fixed(const int intger)
	: _FixedPoint(intger << Fixed::_bits)
{
	std::cout << "Int constructor called" << std::endl;
}
        
Fixed::Fixed(const float Float)
	: _FixedPoint(roundf(Float * (1 << Fixed::_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return ((float)_FixedPoint / (1 << Fixed::_bits));
}

int Fixed::toInt(void) const
{
	return (_FixedPoint >> Fixed::_bits);
}

std::ostream& operator<<(std::ostream &os, const Fixed &f)
{
    os << f.toFloat();
	return (os);
}