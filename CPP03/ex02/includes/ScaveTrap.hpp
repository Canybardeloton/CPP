/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScaveTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:48:51 by agiliber          #+#    #+#             */
/*   Updated: 2025/02/12 14:17:37 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScaveTrap : public ClapTrap
{
	public:
		ScaveTrap(std::string name);
		ScaveTrap(ScaveTrap const& copy);
		ScaveTrap&	operator=(ScaveTrap const& copy);
		void	attack(const std::string& target);
		void	guardGate(void);
		~ScaveTrap();
};
