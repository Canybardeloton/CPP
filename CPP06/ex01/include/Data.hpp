/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:33:01 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/01 16:38:31 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <ostream>
#include <sstream>
#include <iostream>

class Data
{
	public :
		Data();
		Data(Data const & copy);
		Data& operator=(Data const & copy);
		std::string	getName() const;
		~Data();

	private :
		std::string _name;
};

std::ostream &	operator<<(std::ostream &o, Data const &rSym);