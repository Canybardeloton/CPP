/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:35:13 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/02 10:06:02 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Data.hpp"

Data::Data() : _name("Jack")
{
	std::cout << "Data default constructor called." << std::endl;
}

Data::~Data()
{
	std::cout << "Data default destructor called." << std::endl;
}

Data::Data(Data const &src)
{
	std::cout << "Data copy constructor called." << std::endl;
	*this = src;
}

Data &	Data::operator=(Data const &rSym)
{
	std::cout << "Data assignment called." << std::endl;
	if (this != &rSym)
	{
		this->_name = rSym._name;
	}
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, Data const &rSym)
{
	o << rSym.getName();
	return (o);
}

std::string	Data::getName() const
{
	return (this->_name);
}