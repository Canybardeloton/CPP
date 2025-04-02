/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:17:31 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/02 17:16:08 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>
void	function(T const & value)
{
	std::cout << value << std::endl;
}

template <typename T, typename A, typename U>
void	iter(T& array, A& length, const U function)
{
	for (unsigned long i = 0; i < length; i++)
		function(array[i]);
}
