/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:56:50 by agiliber          #+#    #+#             */
/*   Updated: 2025/02/10 11:09:46 by agiliber         ###   ########.fr       */
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
	return ((float)_fixed_value / (float)(1 << _bits_nbr));
}

int	Fixed::toInt(void) const
{
	return (_fixed_value >> _bits_nbr);
}

std::ostream&	operator<<(std::ostream& out, Fixed const& obj)
{
	out << obj.toFloat();
	return (out);
}

bool	Fixed::operator>(Fixed const& obj) const
{
	return (this->_fixed_value > obj._fixed_value);
}

bool	Fixed::operator>=(Fixed const& obj) const
{
	return (this->_fixed_value >= obj._fixed_value);
}

bool	Fixed::operator<(Fixed const& obj) const
{
	return (this->_fixed_value < obj._fixed_value);
}

bool	Fixed::operator<=(Fixed const& obj) const
{
	return (this->_fixed_value <= obj._fixed_value);
}

bool	Fixed::operator==(Fixed const& obj) const
{
	return (this->_fixed_value == obj._fixed_value);
}

bool	Fixed::operator!=(Fixed const& obj) const
{
	return (this->_fixed_value != obj._fixed_value);
}

Fixed	Fixed::operator+(Fixed const& obj) const
{
	Fixed tmp;

	tmp.setRawBits(this->_fixed_value + obj._fixed_value);
	return (tmp);
}

Fixed	Fixed::operator-(Fixed const& obj) const
{
	Fixed tmp;

	tmp.setRawBits(this->_fixed_value - obj._fixed_value);
	return (tmp);
}

Fixed	Fixed::operator*(Fixed const& obj) const
{
	Fixed tmp;

	tmp.setRawBits((this->_fixed_value * obj._fixed_value) >> _bits_nbr);
	return (tmp);
}

Fixed	Fixed::operator/(Fixed const& obj) const
{
	Fixed tmp;

	tmp.setRawBits((this->_fixed_value << _bits_nbr) / obj._fixed_value);
	return (tmp);
}

Fixed& Fixed::operator++(void)
{
	this->_fixed_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);

	operator++();
	return (tmp);
}

Fixed& Fixed::operator--(void)
{
	this->_fixed_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);

	operator--();
	return (tmp);
}

Fixed const&  Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}

Fixed&  Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

Fixed&  Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}


Fixed const&  Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b ? a : b);
}