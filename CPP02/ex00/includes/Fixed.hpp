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

class Fixed
{
	public :
		Fixed();
		Fixed(const Fixed& new_fixed);
		Fixed&	operator=(const Fixed& new_fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		~Fixed();
	private :
		int					_fixed_value;
		static const int	_bits_nbr = 8;
};

#endif