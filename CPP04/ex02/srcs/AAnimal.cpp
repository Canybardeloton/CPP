/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:07:09 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/30 11:08:35 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
	std::cout << "AAnimal string copy called" << std::endl;
	this->_type = type;
}

AAnimal::AAnimal(const AAnimal& copy)
{
	std::cout << "AAnimal copy cosntructor called" << std::endl;
	*this = copy;
}

AAnimal::~AAnimal()
{
		std::cout << "AAnimal destructor called" << std::endl;
}


AAnimal& AAnimal::operator=(AAnimal const& assign)
{
	this->_type = assign._type;
	return *this;
}

std::string AAnimal::getType(void) const
{
	return this->_type;
}

void	AAnimal::setType(std::string type)
{
	this->_type = type;
}