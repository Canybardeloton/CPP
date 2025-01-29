/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:13:12 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/29 10:21:03 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongDog.hpp"

WrongDog::WrongDog(/* args */) : WrongAnimal("WrongDog")
{
	std::cout << "WrongDog constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog& copy) : WrongAnimal(copy)
{
	std::cout << "WrongDog copy cosntructor called" << std::endl;
	this->_type = copy._type;
}

WrongDog::~WrongDog()
{
	std::cout << "WrongDog destructor called" << std::endl;
}

void	WrongDog::makeSound(void) const
{
	std::cout << "Piou Piou?" << std::endl;
}

WrongDog&	WrongDog::operator=(const WrongDog& rhs)
{
	this->_type = rhs._type;
	return *this;
}