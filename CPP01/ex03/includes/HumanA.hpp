/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:49:02 by agiliber          #+#    #+#             */
/*   Updated: 2024/12/04 14:09:12 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
 #define HUMANA_HPP

# include "Weapon.hpp"
# include "HumanB.hpp"

class HumanA
{
	public :
		HumanA(std::string name, Weapon& weapon);
		void	attack(void);
		~HumanA();
	private :
		std::string	_name;
		Weapon&		_weapon;
};



#endif