/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:23:59 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/22 11:14:27 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	if (this != &src)
	{
		_vectorContainer = src._vectorContainer;
		_dequeContainer = src._dequeContainer;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

bool	PmergeMe::isPositiveInteger(const char* str)
{
	if (!str || *str == '\0')
		return (false);
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	long num = std::strtol(str, NULL, 10);
	if (num > INT_MAX || num < 0)
		return (false);
	return (true);
}

bool	PmergeMe::parseInput(int argc, char** argv)
{
	for (int i = 1; i < argc; i++)
	{
		if (!isPositiveInteger(argv[i]))
		{
			std::cerr << "Error: invalid input" << std::endl;
			return (false);
		}
		int num = std::atoi(argv[i]);
		_vectorContainer.push_back(num);
		_dequeContainer.push_back(num);
	}
	if (_vectorContainer.empty())
	{
		std::cerr << "Error: no valid input" << std::endl;
		return (false);
	}
	return (true);
}

void	PmergeMe::displayBeforeSort()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vectorContainer.size(); i++)
	{
		std::cout << _vectorContainer[i];
		if (i < _vectorContainer.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::displayAfterSort()
{
	std::cout << "After: ";
	for (size_t i = 0; i < _vectorContainer.size(); i++)
	{
		std::cout << _vectorContainer[i];
		if (i < _vectorContainer.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::displayResults(double vectorTime, double dequeTime)
{
	std::cout << "Time to process a range of " << _vectorContainer.size()
			  << " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeContainer.size()
			  << " elements with std::deque : " << dequeTime << " us" << std::endl;
}

std::vector<int> PmergeMe::JacobsthalSequence(int n)
{
	std::vector<int> jacobsthal;

	if (n <= 0)
		return (jacobsthal);
	jacobsthal.push_back(0);
	if (n > 1)
		jacobsthal.push_back(1);
	int i = 2;
	while (i < n && i < 100)
	{
		int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		jacobsthal.push_back(next);
		i++;
	}
	return (jacobsthal);
}

void	PmergeMe::sortWithVector()
{
	if (_vectorContainer.empty())
		return;
	int extraElement = -1;
	bool hasExtraElement = false;
	if (_vectorContainer.size() % 2 != 0)
	{
		extraElement = _vectorContainer.back();
		_vectorContainer.pop_back();
		hasExtraElement = true;
	}
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < _vectorContainer.size(); i += 2)
	{
		if (_vectorContainer[i] > _vectorContainer[i + 1])
			pairs.push_back(std::make_pair(_vectorContainer[i], _vectorContainer[i + 1]));
		else
			pairs.push_back(std::make_pair(_vectorContainer[i + 1], _vectorContainer[i]));
	}
	if (pairs.empty())
	{
		if (hasExtraElement)
			_vectorContainer.push_back(extraElement);
		return;
	}
	for (size_t i = 1; i < pairs.size(); i++)
	{
		std::pair<int, int> key = pairs[i];
		int j = i - 1;

		while (j >= 0 && pairs[j].first > key.first)
		{
			pairs[j + 1] = pairs[j];
			j--;
		}
		pairs[j + 1] = key;
	}

	std::vector<int> mainChain;
	std::vector<int> pendChain;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pendChain.push_back(pairs[i].second);
	}
	if (!pendChain.empty())
		mainChain.insert(mainChain.begin(), pendChain[0]);
	std::vector<int> jacobsthalIdx = JacobsthalSequence(pendChain.size());
	std::vector<bool> inserted(pendChain.size(), false);
	inserted[0] = true;
	for (size_t i = 1; i < jacobsthalIdx.size(); i++)
	{
		int idx = jacobsthalIdx[i];
		if (idx > 0 && idx < static_cast<int>(pendChain.size()) && !inserted[idx])
		{
			int val = pendChain[idx];
			std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
			mainChain.insert(pos, val);
			inserted[idx] = true;
		}
	}
	for (size_t i = 1; i < pendChain.size(); i++)
	{
		if (!inserted[i])
		{
			int val = pendChain[i];
			std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
			mainChain.insert(pos, val);
		}
	}
	if (hasExtraElement)
	{
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), extraElement);
		mainChain.insert(pos, extraElement);
	}
	_vectorContainer = mainChain;
}

void	PmergeMe::sortWithDeque()
{
	if (_dequeContainer.empty())
		return;

	int extraElement = -1;
	bool hasExtraElement = false;
	if (_dequeContainer.size() % 2 != 0)
	{
		extraElement = _dequeContainer.back();
		_dequeContainer.pop_back();
		hasExtraElement = true;
	}

	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < _dequeContainer.size(); i += 2)
	{
		if (_dequeContainer[i] > _dequeContainer[i + 1])
			pairs.push_back(std::make_pair(_dequeContainer[i], _dequeContainer[i+1]));
		else
			pairs.push_back(std::make_pair(_dequeContainer[i+1], _dequeContainer[i]));
	}
	if (pairs.empty())
	{
		if (hasExtraElement)
		{
			_dequeContainer.push_back(extraElement);
		}
		return;
	}
	for (size_t i = 1; i < pairs.size(); i++)
	{
		std::pair<int, int> key = pairs[i];
		int j = i - 1;

		while (j >= 0 && pairs[j].first > key.first)
		{
			pairs[j+1] = pairs[j];
			j--;
		}
		pairs[j+1] = key;
	}
	std::deque<int> mainChain;
	std::deque<int> pendChain;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pendChain.push_back(pairs[i].second);
	}
	if (!pendChain.empty())
	{
		mainChain.push_front(pendChain[0]);
	}
	std::vector<int> jacobsthalIdx = JacobsthalSequence(pendChain.size());
	std::vector<bool> inserted(pendChain.size(), false);
	if (!pendChain.empty())
		inserted[0] = true;
	for (size_t i = 1; i < jacobsthalIdx.size(); i++)
	{
		int idx = jacobsthalIdx[i];
		if (idx > 0 && static_cast<size_t>(idx) < pendChain.size() && !inserted[idx])
		{
			int val = pendChain[idx];
			std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
			mainChain.insert(pos, val);
			inserted[idx] = true;
		}
	}
	for (size_t i = 1; i < pendChain.size(); i++)
	{
		if (!inserted[i])
		{
			int val = pendChain[i];
			std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
			mainChain.insert(pos, val);
		}
	}
	if (hasExtraElement)
	{
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), extraElement);
		mainChain.insert(pos, extraElement);
	}
	_dequeContainer = mainChain;
}