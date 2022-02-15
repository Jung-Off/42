
#include "Fixed.hpp"

Fixed::Fixed() : _FixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}
											//이것의 이유를 모르겠음
Fixed::Fixed(const int Intger) : _FixedPoint(Intger << Fixed::_bits)
{
	std::cout << "Intger constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	(*this) = fixed;
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
	std::cout << "getRawBits member function called" << std::endl;
	return(_FixedPoint);
}

void Fixed::setRawBits(const int raw)
{
	_FixedPoint = raw;
}

int Fixed::toInt(void) const
{
	return (_FixedPoint >> Fixed::_bits);
}
