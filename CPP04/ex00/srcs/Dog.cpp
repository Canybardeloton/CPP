/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:28:25 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/21 15:12:42 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->sound = "Wouaf";
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
	this->type = assign.type;
	return *this;
}
