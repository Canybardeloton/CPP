/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:45:28 by agiliber          #+#    #+#             */
/*   Updated: 2025/02/12 14:16:42 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const& copy);
		ClapTrap&	operator=(ClapTrap const& copy);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		~ClapTrap();
	protected:
		std::string		_name;
		unsigned int	_HitPoints;
		unsigned int	_EnergyPoints;
		unsigned int	_AttackDmage;
};
