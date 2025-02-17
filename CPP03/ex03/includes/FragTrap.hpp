/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:49:41 by agiliber          #+#    #+#             */
/*   Updated: 2025/02/12 14:17:51 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScaveTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(FragTrap const& copy);
		FragTrap&	operator=(FragTrap const& copy);
		~FragTrap();
	void	highFivesGuys(void);
};
