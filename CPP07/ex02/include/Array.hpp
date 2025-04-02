/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:17:31 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/02 17:29:11 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <class T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(Array& const copy);
		Array&	operator=(Array& const copy)
		~Array();

	private:

};
