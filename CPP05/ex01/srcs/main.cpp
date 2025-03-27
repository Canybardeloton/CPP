/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:29:18 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/27 13:59:15 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bbl("Armel", 16);
		Bureaucrat bbl2("Arthur", 59);
		Form	formy("Form-42069", 58, 55);

		std::cout << bbl << std::endl;
		std::cout << bbl2 << std::endl;
		std::cout << formy << std::endl;

		formy.beSigned(bbl);
		std::cout << formy << std::endl;
		formy.beSigned(bbl2);
		std::cout << formy << std::endl;
		formy.beSigned(bbl);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
