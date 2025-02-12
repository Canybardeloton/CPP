/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:51:35 by agiliber          #+#    #+#             */
/*   Updated: 2025/02/12 14:39:54 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap::ClapTrap(name)
{
	std::cout << "FragTrap " << name << " is now constructed!" << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDmage = 30;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap::ClapTrap(copy)
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(copy);
}

FragTrap&	FragTrap::operator=(const FragTrap& copy)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap is now destroyed!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap is asking for a high five!" << std::endl;
}