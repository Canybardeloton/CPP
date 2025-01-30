/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:28:25 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/30 11:10:49 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : AAnimal("Cat"), _brain(new Brain())
{
	std::cout << "Cat constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete(this->_brain);
}

Cat::Cat(const Cat &copy) : AAnimal(copy), _brain(new Brain(*copy._brain))
{
	*this = copy;
}

Cat &Cat::operator=(const Cat &assign)
{
	this->_type = assign._type;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meouw" << std::endl;
}
