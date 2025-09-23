/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:20:49 by rraumain          #+#    #+#             */
/*   Updated: 2025/09/23 22:34:18 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

std::ostream	&operator<<(std::ostream &lhs, const Fixed &rhs)
{
	return (lhs << rhs.toFloat());
}

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed &copy) 
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		_rawBits = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int raw)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(raw << _fractionalBits);
}

Fixed::Fixed(const float raw)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(raw * (1 << _fractionalBits)));
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
	return ((float)_rawBits / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (_rawBits / (1 << _fractionalBits));
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
	return (Fixed(_rawBits + rhs._rawBits));
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(_rawBits - rhs._rawBits));
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	if (rhs._rawBits == 0) 
        return Fixed(0);
	return (Fixed(toFloat() / rhs.toFloat()));
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
