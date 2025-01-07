/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:56:50 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/06 16:04:42 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _fixed_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& new_fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(new_fixed);
}

Fixed::Fixed(const int nbr) : _fixed_value(nbr << _bits_nbr)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float flt) : _fixed_value(roundf(flt * (1 << _bits_nbr)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& new_fixed)
{
	if (this != &new_fixed)
	{
		std::cout << "Copy assignement operator called" << std::endl;
		setRawBits(new_fixed.getRawBits());
	}
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_value);
}

void	Fixed::setRawBits(int const raw)
{
	_fixed_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)_fixed_value / (float)(1 << _bits_nbr);
}

int	Fixed::toInt(void) const
{
	return _fixed_value >> _bits_nbr;
}

std::ostream&	operator<<(std::ostream& o, Fixed const& rSym)
{
	o << rSym.toFloat();
	return o;
}