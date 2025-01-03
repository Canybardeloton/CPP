/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:01:59 by agiliber          #+#    #+#             */
/*   Updated: 2024/12/09 13:28:45 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
	#define HARL_HPP

# include <string>
# include <iostream>

class Harl
{
	public :
		Harl();
		void	complain(std::string level);
		~Harl();
	private :
		void	debug()
		{
			std::cout << "DEBUG: I love having extra bacon for my burger." << std::endl;
		}

		void	info()
		{
			std::cout << "INFO: I cannot believe adding extra bacon costs more money." << std::endl;
		}

		void	warning()
		{
			std::cout << "WARNING: I think I deserve to have some extra bacon for free." << std::endl;
		}

		void	error()
		{
			std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
		}
};

#endif