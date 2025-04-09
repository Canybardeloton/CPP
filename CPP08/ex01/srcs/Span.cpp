/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:54:53 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/09 12:03:19 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

Span::Span(unsigned int N) : _size(N)
{
	_tab.reserve(_size);
	std::cout << "Span initiated with an array of size " << _size << "." << std::endl;
}

Span::Span(const Span& copy) : _tab(copy._tab), _size(copy._size)
{
	std::cout << "Span copy initiated." << std::endl;
}

Span&	Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		_size = copy._size;
		_tab = copy._tab;
		std::cout << "Span assignement initiated." << std::endl;
	}
	return (*this);
}

Span::~Span()
{
	std::cout << "Span destructed." << std::endl;
}

void	Span::addNumber(int nb)
{
	if (_tab.size() < _tab.capacity())
		_tab.push_back(nb);
	else
		throw (NoMoreRoom());
}

size_t	Span::shortestSpan()
{
	if (_tab.size() <= 1)
		throw (EmptyVector());
	else
	{
		std::vector<int> sorted(_tab);
		std::sort(sorted.begin(), sorted.end());

		size_t min_span = sorted[1] - sorted[0];

		for (size_t i = 0; i < sorted.size(); i++)
		{
			size_t current_span = static_cast<size_t>(sorted[i] - sorted[i - 1]);
			if (current_span < min_span)
				min_span = current_span;
		}
		return (min_span);
	}
}

size_t	Span::longestSpan()
{
	if (_tab.size() <= 1)
		throw (EmptyVector());
	else
	{
		std::vector<int> sorted(_tab);
		std::sort(sorted.begin(), sorted.end());

		std::vector<int>::iterator min_elem = std::min_element(_tab.begin(), _tab.end());
		std::vector<int>::iterator max_elem = std::max_element(_tab.begin(), _tab.end());

		int	min_value = *min_elem;
		int	max_value = *max_elem;
		size_t	max_span = static_cast<size_t>(max_value - min_value);
		return (max_span);
	}
}