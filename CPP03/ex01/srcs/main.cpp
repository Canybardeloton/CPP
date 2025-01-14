/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:30:44 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/14 14:47:12 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScaveTrap.hpp"

int	main()
{
	ClapTrap Hero("Bernard");
	ScaveTrap Robot("Diego");

	Robot.attack("Stephane");
	Hero.attack("Stephane");
	Hero.beRepaired(2);
}