/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:28:10 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/15 15:19:43 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	std::map<std::string, float> ref;
	std::map<std::string, float> input;

	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (0);
	}
	if (CheckFile(ref, input, ",", "data.csv") == false)
	{
		std::cerr << "Error in the reference file." << std::endl;
		return (0);
	}
	CheckFile(input, ref, " | ", av[1]);
	return (0);
}