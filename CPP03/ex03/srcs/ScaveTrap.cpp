/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScaveTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:50:29 by agiliber          #+#    #+#             */
/*   Updated: 2025/02/12 14:27:09 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

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

ScaveTrap::ScaveTrap(const ScaveTrap& copy) : ClapTrap::ClapTrap(copy)
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(copy);
}

ScaveTrap&	ScaveTrap::operator=(const ScaveTrap& copy)
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