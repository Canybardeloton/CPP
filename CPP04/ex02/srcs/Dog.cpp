/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:28:25 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/30 11:11:57 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(void) : AAnimal("Dog"), _brain(new Brain())
{
	std::cout << "Dog constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete(this->_brain);
}

Dog::Dog(const Dog &copy) : AAnimal(copy), _brain(new Brain(*copy._brain))
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
