/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:23:35 by agiliber          #+#    #+#             */
/*   Updated: 2024/12/03 11:03:59 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
 #define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <ctype.h>
# include <stdio.h>

class Zombie
{
	public :
		Zombie();
		void	announce(void);
		void	setName(std::string name);
		~Zombie();
	private :
		std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif