/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:24:21 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/16 15:44:01 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

// Dans main.cpp
int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cerr << "Error: No input sequence provided." << std::endl;
		return 1;
	}

	Pmergeme sorter;

	// Parser et valider l'entrée
	if (!sorter.parseInput(argc, argv)) {
		std::cerr << "Error: Invalid input." << std::endl;
		return 1;
	}

	// Afficher la séquence avant le tri
	sorter.displayBeforeSort();

	// Mesurer le temps pour std::vector
	clock_t start = clock();
	sorter.sortWithVector();
	clock_t end = clock();
	double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // en microsecondes

	// Mesurer le temps pour std::deque
	start = clock();
	sorter.sortWithDeque();
	end = clock();
	double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // en microsecondes

	// Afficher la séquence après le tri
	sorter.displayAfterSort();

	// Afficher les temps
	sorter.displayResults(vectorTime, dequeTime);

	return 0;
}