/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:29:18 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/27 13:40:03 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"


int	main()
{
	try
	{
		Bureaucrat b1("John", 10);
		Bureaucrat b2("Jane", 15);
		Bureaucrat b3("Jack", 150);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;

		b1.increment_grade();
		std::cout << b1 << std::endl;
		b2.decrement_grade();
		std::cout << b2 << std::endl;
		b3.decrement_grade();
		std::cout << b3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}