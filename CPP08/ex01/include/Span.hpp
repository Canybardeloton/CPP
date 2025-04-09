/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:18:45 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/09 11:36:09 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <algorithm>

class Span
{
	public :
		Span(unsigned int N);
		Span(const Span& copy);
		Span&	operator=(const Span& copy);
		~Span();

		void	addNumber(int nb);
		size_t	shortestSpan();
		size_t	longestSpan();

		class NoMoreRoom : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Can't add a new number in container.");
				}
		};

		class EmptyVector : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Not enough element in the container.");
				}
		};

	private :
		std::vector<int>	_tab;
		unsigned int	_size;
};
