/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:56:06 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/06 15:50:00 by agiliber         ###   ########.fr       */
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
		int		toInt( void ) const;
		~Fixed();
	private :
		int					_fixed_value;
		static const int	_bits_nbr = 8;
};

std::ostream&	operator<<( std::ostream& o, Fixed const &rSym );

#endif