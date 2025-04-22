/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:19:53 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/22 11:14:51 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <algorithm>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe();

		bool parseInput(int argc, char** argv);

		void sortWithVector();
		void sortWithDeque();

		void displayResults(double vectorTime, double dequeTime);
		void displayBeforeSort();
		void displayAfterSort();

	private:
		std::vector<int> _vectorContainer;
		std::deque<int> _dequeContainer;

		std::vector<int> JacobsthalSequence(int n);

		bool isPositiveInteger(const char* str);
};