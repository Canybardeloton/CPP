/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:29:18 by agiliber          #+#    #+#             */
/*   Updated: 2025/02/04 12:46:45 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"


int	main()
{
	Bureaucrat b1("John", 1);
	Bureaucrat b2("Jane", 150);
	Bureaucrat b3("Jack", 75);

	std::cout << b1.getGrade() << std::endl;
	std::cout << b2.getGrade() << std::endl;
	std::cout << b3.getGrade() << std::endl;

	b1.increment_grade();
	std::cout << b1.getGrade() << std::endl;
	b2.decrement_grade();
	std::cout << b2.getGrade() << std::endl;
	b3.decrement_grade();
	std::cout << b3.getGrade() << std::endl;

	return (0);
}