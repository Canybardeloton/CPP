/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:03:01 by agiliber          #+#    #+#             */
/*   Updated: 2025/02/03 10:45:57 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl is constructed" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl is destroyed" << std::endl;
}

void	Harl::debug()
{
	std::cout << "DEBUG: I love having extra bacon for my burger." << std::endl;
}

void	Harl::info()
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money." << std::endl;
}

void	Harl::warning()
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for free." << std::endl;
}

void	Harl::error()
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*message[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	i = 0;
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*message[i])();
			return ;
		}
	}
	std::cout << "Wrong level" << std::endl;
}
