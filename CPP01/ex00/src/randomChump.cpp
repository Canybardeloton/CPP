/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:31:58 by agiliber          #+#    #+#             */
/*   Updated: 2024/12/03 10:33:04 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

void 	randomChump(std::string name)
{
	Zombie	*nwZombie;

	nwZombie = newZombie(name);
	nwZombie->announce();
	delete nwZombie;
}