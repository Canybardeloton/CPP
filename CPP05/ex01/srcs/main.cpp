/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:29:18 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/26 16:09:07 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bbl("Armel", 52);
		Bureaucrat bbl2("Arthur", 56);
		Form	formy("Form-42069", 55, 55);
		std::cout << bbl << std::endl;
		std::cout << bbl2 << std::endl;
		std::cout << formy << std::endl;
		formy.beSigned(bbl);
		std::cout << formy << std::endl;
		formy.beSigned(bbl2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
