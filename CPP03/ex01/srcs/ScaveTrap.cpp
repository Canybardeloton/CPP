/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScaveTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:50:29 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/14 14:48:34 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScaveTrap.hpp"

ScaveTrap::ScaveTrap(std::string name) : ClapTrap::ClapTrap(name)
{
	std::cout << "ScaveTrap " << name << " has been constructed!" << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDmage = 20;
}

ScaveTrap::~ScaveTrap()
{
	std::cout << "ScaveTrap has been destructed!" << std::endl;
}

void	ScaveTrap::attack(const std::string& target)
{
	ScaveTrap Enemy(target);

	if (this->_EnergyPoints > 0 && Enemy._HitPoints > 0)
	{
		std::cout << "ScaveTrap " << this->_name << " attacks " << target << ", causing " << this->_AttackDmage << " points of damage!" << std::endl;
		Enemy.takeDamage(this->_AttackDmage);
		this->_EnergyPoints--;
	}
}

void	ScaveTrap::guardGate(void)
{
	std::cout << "ScaveTrap is now in Gate keeper mode." << std::endl;
}