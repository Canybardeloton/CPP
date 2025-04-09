/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:18:45 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/09 13:20:45 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <algorithm>

template <typename T>
class Stack
{
	public :
		void	push(T& element);

		class EmptyVector : public std::exception
		{
				public:
				const char* what() const throw()
				{
					return ("Not enough element in the container.");
				}
		};

	private :
		Stack();
		Stack(const Stack& copy);
		Stack&	operator=(const Stack& copy);
		~Stack();
		std::vector<T&> _tab;
};

class MutantStack : public Stack
{
	public :
		void	push(T& element);

		MutantStack();
		MutantStack(const MutantStack& copy);
		MutantStack&	operator=(const MutantStack& copy);
		~MutantStack();

	private :
		std::vector<T&> _tab;
};