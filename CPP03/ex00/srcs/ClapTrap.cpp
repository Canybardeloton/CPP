/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:47:08 by agiliber          #+#    #+#             */
/*   Updated: 2025/02/12 14:24:21 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _HitPoints(10), _AttackDmage(0), _EnergyPoints(10)
{
	std::cout << "Claptrap " << _name << " constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(copy);
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& copy)
{
	if (this != &copy)
	{
		std::cout << "Copy assignement operator called" << std::endl;
		this->_AttackDmage = copy._AttackDmage;
		this->_EnergyPoints = copy._EnergyPoints;
		this->_HitPoints = copy._HitPoints;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	ClapTrap Enemy(target);

	if (this->_EnergyPoints > 0 && Enemy._HitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_AttackDmage << " points of damage!" << std::endl;
		Enemy.takeDamage(this->_AttackDmage);
		this->_EnergyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_HitPoints = this->_HitPoints - amount;
	std::cout << "ClapTrap " << this->_name << " has taken " << amount << " damage and has " << this->_HitPoints << " health remaining!" <<std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_EnergyPoints > 0 && this->_HitPoints < 10 && this->_HitPoints > 0)
	{
		if (this->_HitPoints + amount <= 10)
			this->_HitPoints = this->_HitPoints + amount;
		else
			this->_HitPoints = 10;
		this->_EnergyPoints--;
		std::cout << "ClapTrap " << this->_name << " has repaired itself for " << amount << ". It has " << this->_HitPoints << " health and " << this->_EnergyPoints << " energy points remaining!" <<std::endl;
	}
}