/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:30:59 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/29 10:20:28 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(std::string type)
{
	std::cout << "Animal string copy called" << std::endl;
	this->_type = type;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
}

Animal &Animal::operator=(const Animal &assign)
{
	this->_type = assign._type;
	return *this;
}

void	Animal::makeSound(void) const
{
	std::cout << "i'm just an animal" << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}