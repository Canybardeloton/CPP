/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:29:18 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/01 15:56:44 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

int	main()
{
	std::string	s1 = "-42";
	std::string	s2 = "i";
	std::string	s3 = "-4.2f";
	std::string	s4 = "2.45";

	std::cout << "INT CONVERSION" <<std::endl;
	ScalarConverter::convert(s1);
	std::cout << std::endl;

	std::cout << "CHAR CONVERSION" <<std::endl;
	ScalarConverter::convert(s2);
	std::cout << std::endl;

	std::cout << "FLOAT CONVERSION" <<std::endl;
	ScalarConverter::convert(s3);
	std::cout << std::endl;

	std::cout << "DOUBLE CONVERSION" <<std::endl;
	ScalarConverter::convert(s4);
	return (0);
}