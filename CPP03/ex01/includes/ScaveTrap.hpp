/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScaveTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:48:51 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/14 14:47:45 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScaveTrap : public ClapTrap
{
	public:
		ScaveTrap(std::string name);
		void	attack(const std::string& target);
		void	guardGate(void);
		~ScaveTrap();
};
