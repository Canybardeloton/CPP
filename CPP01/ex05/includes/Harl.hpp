/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:01:59 by agiliber          #+#    #+#             */
/*   Updated: 2025/02/03 10:45:22 by agiliber         ###   ########.fr       */
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
		void	debug();
		void	info();
		void	warning();
		void	error();
};

#endif