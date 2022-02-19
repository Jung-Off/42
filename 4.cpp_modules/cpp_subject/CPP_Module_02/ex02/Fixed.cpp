
#include "Fixed.hpp"

//Constructor
Fixed::Fixed() : _FixedPoint(0)
	{}

Fixed::Fixed(const int intger)
	: _FixedPoint(intger << Fixed::_bits)
	{}
        
Fixed::Fixed(const float Float)
	: _FixedPoint(roundf(Float * (1 << Fixed::_bits)))
	{}

//Copy
Fixed::Fixed(const Fixed& fixed)
{
	(*this) = fixed;	// operator=
}

//Destructor
Fixed::~Fixed()
	{}

int Fixed::getRawBits() const
{
	return(_FixedPoint);
}

void Fixed::setRawBits(const int raw)
{
	_FixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)_FixedPoint / (1 << Fixed::_bits));
}

int Fixed::toInt(void) const
{
	return (_FixedPoint >> Fixed::_bits);
}

//Comparison
Fixed& Fixed::operator=(const Fixed& fixed)
{
	if (this != &fixed)						
		_FixedPoint = fixed.getRawBits();	
	return (*this);							
}

bool Fixed::operator>(const Fixed& fixed)
{
	if (_FixedPoint > fixed.getRawBits())
		return(true);
	return (false);
}

bool Fixed::operator<(const Fixed& fixed)
{
	if (_FixedPoint < fixed.getRawBits())
		return(true);
	return (false);
}

bool Fixed::operator>=(const Fixed& fixed)
{
	if (_FixedPoint >= fixed.getRawBits())
		return(true);
	return (false);
}

bool Fixed::operator<=(const Fixed& fixed)
{
	if (_FixedPoint <= fixed.getRawBits())
		return(true);
	return (false);
}

bool Fixed::operator==(const Fixed& fixed)
{
	if (_FixedPoint == fixed.getRawBits())
		return(true);
	return (false);
}

bool Fixed::operator!=(const Fixed& fixed)
{
	if (_FixedPoint != fixed.getRawBits())
		return(true);
	return (false);
}

//arithmetic
Fixed Fixed::operator+(const Fixed& fixed)
{
	Fixed sum(toFloat() + fixed.toFloat());
	return (sum);
}

Fixed Fixed::operator-(const Fixed& fixed)
{
	Fixed min(toFloat() - fixed.toFloat());
	return (min);
}

Fixed Fixed::operator*(const Fixed& fixed)
{
	Fixed mul(toFloat() * fixed.toFloat());
	return (mul);
}

Fixed Fixed::operator/(const Fixed& fixed)
{
	Fixed div(toFloat() / fixed.toFloat());
	return (div);
}

//incre, decre
Fixed& Fixed::operator++()	//전위
{
	_FixedPoint++;
	return (*this);
}

const Fixed Fixed::operator++(int)
{
	Fixed ret(*this);
	_FixedPoint++;
	return (ret);
}

Fixed& Fixed::operator--()
{
	_FixedPoint--;
	return (*this);
}

const Fixed Fixed::operator--(int)
{
	Fixed ret(*this);
	_FixedPoint--;
	return (ret);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return(b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return(b);
}

std::ostream& operator<<(std::ostream &os, const Fixed &f)
{
    os << f.toFloat();
	return (os);
}