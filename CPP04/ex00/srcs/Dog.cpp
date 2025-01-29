/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:28:25 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/29 10:20:36 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	*this = copy;
}

Dog &Dog::operator=(const Dog &assign)
{
	this->_type = assign._type;
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouaf" << std::endl;
}
