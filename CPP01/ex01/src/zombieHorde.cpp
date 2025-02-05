/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:40:32 by agiliber          #+#    #+#             */
/*   Updated: 2025/02/03 10:39:13 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	int	i;

	Zombie *zombieHorde = new Zombie[N];
	for (i = 0; i < N; i++)
	{
		zombieHorde[i].setName(name);
		zombieHorde[i].announce();
	}
	return (zombieHorde);
}