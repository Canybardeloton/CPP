/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:47:37 by agiliber          #+#    #+#             */
/*   Updated: 2025/02/03 10:50:33 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
 #define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
	public :
		Weapon(std::string weapon);
		std::string	getType() const;
		void		setType(std::string type);
		~Weapon();
	private :
		std::string	_type;
};

#endif