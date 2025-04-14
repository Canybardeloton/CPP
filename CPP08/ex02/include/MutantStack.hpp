/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:18:45 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/14 10:17:37 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <list>

template <class T>
class MutantStack : public std::stack<T>
{
	public :
		MutantStack();
		MutantStack(MutantStack<T> const &copy);
		MutantStack<T>&	operator=(MutantStack<T> const &copy);
		~MutantStack();

		typedef	typename std::stack<T>::container_type::iterator	iterator;
		iterator			begin();
		iterator			end();

	private :
};

template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout << "MutantStack initiated." << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &copy) : std::stack<T>(copy)
{
	std::cout << "MutantStack copy initiated." << std::endl;
}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(MutantStack<T> const &copy)
{
	if (this != &copy)
	{
		std::cout << "MutantStack assignement initiated." << std::endl;
	}
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack destructed." << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return std::stack<T>::c.end();
}