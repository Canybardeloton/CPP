/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:48:59 by agiliber          #+#    #+#             */
/*   Updated: 2024/12/04 14:00:13 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
 #define HUMANB_HPP

# include "Weapon.hpp"
# include "HumanA.hpp"

class HumanB
{
	public :
		HumanB(std::string name);
		void	attack(void);
		void	setWeapon(Weapon& weapon);
		~HumanB();
	private :
		std::string	_name;
		Weapon*		_weapon;
};

#endif