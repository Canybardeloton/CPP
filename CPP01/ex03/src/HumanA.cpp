/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:48:15 by agiliber          #+#    #+#             */
/*   Updated: 2025/02/03 10:51:29 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	std::cout << _name << " is constructed" << std::endl;
	std::cout << _name << " takes a " << _weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << _name << " is destroyed" << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << _weapon.getType() << std::endl;
}