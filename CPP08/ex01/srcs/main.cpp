/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:28:10 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/09 12:17:16 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
		std::cout << std::endl;

		Span sp3 = Span(5);
		sp3.addNumber(1);
		sp3.addNumber(2);
		sp3.addNumber(3);
		sp3.addNumber(4);
		sp3.addNumber(5);
		std::cout << "Shortest span : " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp3.longestSpan() << std::endl;
		std::cout << std::endl;

		srand(time(NULL));
		Span sp4 = Span(10000);
		for (int i = 0; i < 10000; i++)
		{
			sp4.addNumber(rand() % 100000);
		}
		std::cout << "Shortest span : " << sp4.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp4.longestSpan() << std::endl;
		std::cout << std::endl;

		Span sp2 = Span(0);
		std::cout << "Shortest span : " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp2.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}