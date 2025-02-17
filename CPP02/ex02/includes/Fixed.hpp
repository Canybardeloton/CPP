/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:56:06 by agiliber          #+#    #+#             */
/*   Updated: 2025/02/10 14:18:39 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
	#define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class Fixed
{
	public :
		Fixed();
		Fixed(const int nbr);
		Fixed(const float flt);
		Fixed(const Fixed& new_fixed);
		Fixed&	operator=(const Fixed& new_fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		bool	operator>(Fixed const& obj) const;
		bool	operator>=(Fixed const& obj) const;
		bool	operator<(Fixed const& obj) const;
		bool	operator<=(Fixed const& obj) const;
		bool	operator==(Fixed const& obj) const;
		bool	operator!=(Fixed const& obj) const;
		int		toInt( void ) const;
		Fixed	operator+(Fixed const& obj) const;
		Fixed	operator-(Fixed const& obj) const;
		Fixed	operator*(Fixed const& obj) const;
		Fixed	operator/(Fixed const& obj) const;
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);
		static Fixed&  max(Fixed &a, Fixed &b);
		static Fixed const&  max(Fixed const &a, Fixed const &b);
		static Fixed&  min(Fixed &a, Fixed &b);
		static Fixed const&  min(Fixed const &a, Fixed const &b);
		~Fixed();
	private :
		int					_fixed_value;
		static const int	_bits_nbr = 8;
};

std::ostream&	operator<<( std::ostream& o, Fixed const &obj );

#endif