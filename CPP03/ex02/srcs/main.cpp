/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:30:44 by agiliber          #+#    #+#             */
/*   Updated: 2025/02/12 14:44:37 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int	main()
{
	ClapTrap Hero("Bernard");
	ScaveTrap Robot("Diego");
	FragTrap Mutant("Arthur");

	Mutant.attack("Stephane");
	Robot.attack("Stephane");
	Hero.attack("Stephane");
	Hero.beRepaired(2);
	Robot.beRepaired(10);
	Mutant.beRepaired(10);
}