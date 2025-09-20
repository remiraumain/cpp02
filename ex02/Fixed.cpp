/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:20:49 by rraumain          #+#    #+#             */
/*   Updated: 2025/09/21 00:08:13 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

std::ostream	&operator<<(std::ostream &lhs, const Fixed &rhs)
{
	return (lhs << rhs.toFloat());
}

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _rawBits(0) {}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed &copy) 
{
	if (this != &copy)
		this->_rawBits = copy._rawBits;
	return (*this);
}

Fixed::~Fixed(void) {}

Fixed::Fixed(const int raw)
{
	setRawBits(raw << _fractionalBits);
}

Fixed::Fixed(const float raw)
{
	const int	scale = 1 << _fractionalBits;
	const float	scaled = raw * scale;
	int	encoded = static_cast<int>(roundf(scaled));
	setRawBits(encoded);
}

int	Fixed::getRawBits(void) const 
{
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	const int	scale = 1 << _fractionalBits;
	float	decoded = static_cast<float>(_rawBits);
	return (decoded / scale);
}

int		Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBits);
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (_rawBits > rhs._rawBits);
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (_rawBits < rhs._rawBits);
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (_rawBits >= rhs._rawBits);
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (_rawBits <= rhs._rawBits);
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (_rawBits == rhs._rawBits);
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (_rawBits != rhs._rawBits);
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	Fixed	res;
	res.setRawBits(_rawBits + rhs._rawBits);
	return (res);
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	Fixed	res;
	res.setRawBits(_rawBits - rhs._rawBits);
	return (res);
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	long long	calc = static_cast<long long>(_rawBits) * rhs._rawBits;
	Fixed	res;
	res._rawBits = static_cast<int>(calc >> _fractionalBits);
	return (res);
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	if (rhs._rawBits == 0) 
        return Fixed(0);

	long long	calc = static_cast<long long>(_rawBits) << _fractionalBits;
	Fixed	res;
	res._rawBits = static_cast<int>(calc / rhs._rawBits);
	return (res);
}

Fixed	&Fixed::operator++(void)
{
	_rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	copy(*this);
	_rawBits++;
	return (copy);
}

Fixed	&Fixed::operator--(void)
{
	_rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	copy(*this);
	_rawBits--;
	return (copy);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}
