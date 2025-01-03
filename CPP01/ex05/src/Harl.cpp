/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:03:01 by agiliber          #+#    #+#             */
/*   Updated: 2024/12/09 13:28:59 by agiliber         ###   ########.fr       */
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

void	Harl::complain(std::string level)
{
	void		(Harl::*message[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
		{
			(this->*message[i])();
			return ;
		}
		i++;
	}
	std::cout << "Wrong level" << std::endl;
}
