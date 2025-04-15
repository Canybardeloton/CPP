/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:28:10 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/15 11:38:06 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	std::map<std::string, float> ref;
	std::map<std::string, float> input;

	if (ac != 2)
		return (0);
	if (CheckFile(ref, ",", "data.csv") == false)
	{
		std::cerr << "Error in the reference file." << std::endl;
		return (0);
	}
	if (!CheckFile(input, " | ", av[1]))
	{
		std::cerr << "Error in the input file." << std::endl;
		return (0);
	}
	if (ref.empty())
		std::cout << "Ref Map vide !!" << std::endl;
	if (input.empty())
		std::cout << "Input Map vide !!" << std::endl;
	std::cout << "Tout est bon !!" << std::endl;
	return (0);
}