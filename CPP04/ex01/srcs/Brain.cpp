/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:46:52 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/30 10:53:56 by agiliber         ###   ########.fr       */
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
	for (int i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];
}

Brain&  Brain::operator=(Brain const& assign)
{
	std::cout << "Brain copy assignement operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = assign.ideas[i];
	return *this;
}

void	Brain::overthinkIdeas()
{
	const std::string randomThings[] = {
		"toilet paper", "toothpaste", "shampoo", "soap", "towel", "toothbrush",
	};
	for (int i = 0; i < 100; i++)
		this->ideas[i] = randomThings[rand() % 6];
}


void	Brain::printIdeas()
{
	for (int i = 0; i < 100; i++)
		std::cout << "Idea " << i + 1 << ": " << this->ideas[i] << std::endl;
}