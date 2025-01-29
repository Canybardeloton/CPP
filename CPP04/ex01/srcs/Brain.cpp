/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:46:52 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/29 11:29:16 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	overthinkIdeas();
	printIdeas();
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = copy._ideas[i];
}

Brain&  Brain::operator=(Brain const& assign)
{
	std::cout << "Brain copy assignement operator called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = assign._ideas[i];
	return *this;
}

void	Brain::overthinkIdeas()
{
	const std::string randomThings[] = {
		"toilet paper", "toothpaste", "shampoo", "soap", "towel", "toothbrush",
	};
	for (size_t i = 0; i < 100; i++)
		this->_ideas[i] = randomThings[rand() % 12];
}


void	Brain::printIdeas()
{
	for (size_t i = 0; i < 100; i++)
		std::cout << "Idea " << i + 1 << ": " << this->_ideas[i] << std::endl;
}