/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:18:45 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/09 10:42:05 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <algorithm>

class NotFoundException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("No instance of the value found in container");
		}
};

template <typename T>
typename T::size_type	easyfind(T& input, int nb)
{
	typename T::iterator i;
	i = std::find(input.begin(), input.end(), nb);
	if (i == input.end())
		throw (NotFoundException());
	return (std::distance(input.begin(), i));
}

template <size_t N>
size_t easyfind(int (&input)[N], int nb)
{
	for (size_t i = 0; i < N; i++)
	{
		if (input[i] == nb)
			return (i);
	}
	throw (NotFoundException());
}