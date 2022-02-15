
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
	if (this != &fixed)						// 자기자신과 같으면 굳이 해줄 필요가 없으니까!
		_FixedPoint = fixed.getRawBits();	// getRawBits()
	return (*this);							// b자체 의 참조값 반환!
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
