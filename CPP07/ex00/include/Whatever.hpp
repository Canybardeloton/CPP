/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:17:31 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/02 15:06:55 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>
void	swap(T& a, T& b)
{
	std::swap(a, b);
}

template <typename T>
T	min(T& a, T& b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

template <typename T>
T	max(T& a, T& b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
