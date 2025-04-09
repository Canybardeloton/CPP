/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:54:53 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/09 13:17:05 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"

MutantStack::MutantStack()
{
	std::cout << "MutantStack initiated." << std::endl;
}

MutantStack::MutantStack(const MutantStack& copy)
{
	std::cout << "MutantStack copy initiated." << std::endl;
}

MutantStack&	MutantStack::operator=(const MutantStack& copy)
{
	if (this != &copy)
	{
		std::cout << "MutantStack assignement initiated." << std::endl;
	}
	return (*this);
}

MutantStack::~MutantStack()
{
	std::cout << "MutantStack destructed." << std::endl;
}