/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:23:35 by agiliber          #+#    #+#             */
/*   Updated: 2024/12/03 10:35:01 by agiliber         ###   ########.fr       */
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
		Zombie(std::string name);
		void		announce(void);
		~Zombie();
	private :
		std::string	_name;
};

Zombie*		newZombie(std::string name);
void		randomChump(std::string name);

#endif