/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:24:21 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/22 11:28:11 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"
#include <sstream>

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: No input sequence provided." << std::endl;
		return (1);
	}

	PmergeMe sorter;
	if (!sorter.parseInput(argc, argv))
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	sorter.displayBeforeSort();
	PmergeMe sorter2(sorter);

	clock_t start = clock();
	sorter.sortWithVector();
	clock_t end = clock();
	double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // en microsecondes

	start = clock();
	sorter2.sortWithDeque();
	end = clock();
	double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // en microsecondes

	sorter.displayAfterSort();
	sorter.displayResults(vectorTime, dequeTime);

	return (0);
}