/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:20:49 by rraumain          #+#    #+#             */
/*   Updated: 2025/09/19 14:04:31 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

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
		this->_rawBits = copy.getRawBits();
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
	float	decoded = static_cast<float>(getRawBits());
	return (decoded / scale);
}

int		Fixed::toInt(void) const
{
	return (static_cast<int>(toFloat()));
}

std::ostream	&operator<<(std::ostream &lhs, const Fixed &rhs)
{
	return (lhs << rhs.toFloat());
}
