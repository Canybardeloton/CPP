/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:19:53 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/16 15:27:50 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <chrono>


class Pmergeme
{
	public:
		Pmergeme(unsigned int num);
		Pmergeme(const Pmergeme& copy);
		Pmergeme&	operator=(const Pmergeme& copy);
		~Pmergeme();

		template<typename T>
		void	MergeSort(T& container, int left, int right);

		template <typename T>
		std::vector<int>	JacobsthalSequence(int n);

	private:
		std::vector<int>	_vec;
		std::deque<int>		_dqe;

	void	before(const std::string& input);
	void	after(const std::string& final_input);
	bool	checkInput(const std::string& input);
	void	sortWithVector();

};