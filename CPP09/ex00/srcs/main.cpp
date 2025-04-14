/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:28:10 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/14 12:20:31 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int	main(void)
{
	try
	{
		int input[] = {1, 2, 4, 5, 10};
		int to_find = 10;

		size_t index = ::easyfind(input, to_find);
		std::cout << "Found value " << to_find << " at index " << index << std::endl;

		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(4);
		vec.push_back(5);
		vec.push_back(10);
		size_t vec_index = ::easyfind(vec, 4);
		std::cout << "Found value 4 at index " << vec_index << " in vector" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}