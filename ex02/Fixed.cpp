#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
}

Fixed::Fixed(int const n)
{
	this->_value = n << this->_fractionalBits;
}

Fixed::Fixed(float const f)
{
	this->_value = roundf(f * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	this->_value = other._value;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << this->_fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> this->_fractionalBits);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other._value);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other._value);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other._value);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	++this->_value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	this->_value++;
	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	--this->_value;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	this->_value--;
	return (temp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}