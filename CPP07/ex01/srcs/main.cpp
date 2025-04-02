/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:17:11 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/02 17:20:46 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Iter.hpp"

int main(void)
{
	std::string array[] = {"hello"};
	int tab[] = {1, 2, 3, 4};
	unsigned long length;

	length = 1;
	::iter(array, length, function<std::string>);
	std::cout << std::endl;

	length = 4;
	::iter(tab, length, function<int>);

	return 0;
}