/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:28:25 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/21 15:12:48 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &copy)
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
