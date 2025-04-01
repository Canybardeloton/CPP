/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:39:33 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/01 15:58:34 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

static void	error()
{
	std::cout << "char impossible" << std::endl;
	std::cout << "int : " << 0 << std::endl;
	std::cout << "float : " << 0 << "f" << std::endl;
	std::cout << "double : " << 0 << std::endl;
}

static void	convertChar(std::string input)
{
	std::cout << "char : " << input[0] << std::endl;
	std::cout << "int : " << static_cast<int>(input[0]) << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(input[0]) << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(input[0]) << std::endl;
}

static void	convertInt(std::string input)
{
	int	num = std::atoi(input.c_str());

	if (num < 0 || num > 127)
		std::cout << "char: impossible" << std::endl;
	else if (num >= 32 && num <= 127)
		std::cout << "char : " << static_cast<char>(num) << std::endl;
	else
		std::cout << "char : not printable" << std::endl;
	std::cout << "int : " << num << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

static void	convertFloat(std::string input)
{
	float	num = std::atof(input.c_str());
	int		nb = static_cast<int>(num);

	if (num < 0 || num > 127)
		std::cout << "char: impossible" << std::endl;
	else if (nb >= 32 && nb <= 127)
		std::cout << "char : " << static_cast<char>(nb) << std::endl;
	else
		std::cout << "char : not printable" << std::endl;
	std::cout << "int : " << nb << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(2) <<num << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(2) << static_cast<double>(static_cast<int>(num)) << std::endl;
}

static void	convertDouble(std::string input)
{
	char *end;
	double	num = std::strtod(input.c_str(), &end);
	int		nb = static_cast<int>(num);

	if (*end != '\0')
	{
		error();
		return ;
	}
	if (num < 0 || num > 127)
		std::cout << "char: impossible" << std::endl;
	else if (nb >= 32 && nb <= 127)
		std::cout << "char : " << static_cast<char>(nb) << std::endl;
	else
		std::cout << "char : not printable" << std::endl;
	std::cout << "int : " << nb << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(2) << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(2) << num << std::endl;
}

static void	inffMin()
{
	std::cout << "char impossible" << std::endl;
	std::cout << "int : " << INT_MIN << std::endl;
	std::cout << "float : " << __FLT_MIN__ << "f" << std::endl;
	std::cout << "double : " << __DBL_MIN__ << std::endl;
}

static void	inffMax()
{
	std::cout << "char impossible" << std::endl;
	std::cout << "int : " << INT_MAX << std::endl;
	std::cout << "float : " << __FLT_MAX__ << "f" << std::endl;
	std::cout << "double : " << __DBL_MAX__ << std::endl;
}

static void	nan()
{
	std::cout << "char impossible" << std::endl;
	std::cout << "int : " << 0 << std::endl;
	std::cout << "float : " << 0 << "f" << std::endl;
	std::cout << "double : " << 0 << std::endl;
}

void	ScalarConverter::convert(std::string input)
{
	if (!isdigit(input[0]))
	{
		if (input.length() == 1)
			convertChar(input);
		else if (isdigit(input[1]) && input.find(".") == std::string::npos)
			convertInt(input);
		else if (isdigit(input[1]) && input[input.length() - 1] == 'f')
			convertFloat(input);
		else if (isdigit(input[1]) && input.find(".") != std::string::npos)
			convertDouble(input);
		else if (input == "-inf" || input == "-inff")
			inffMin();
		else if (input == "+inf" || input == "+inff")
			inffMax();
		else if (input == "nan" || input == "nanf")
			nan();
		else
			error();
	}
	else if (input[input.length() - 1] == 'f')
	{
		long unsigned int	i = 0;

		while (i < input.length() - 1 && (isdigit(input[i]) || input[i] == '.'))
			i++;
		if (i == input.length() - 1)
			convertFloat(input);
		else
			error();
	}
	else if (input.find(".") != std::string::npos)
	{
		long unsigned int	i = 0;

		while (isdigit(input[i]) || input[i] == '.')
			i++;
		if (i == input.length())
			convertDouble(input);
		else
			error();
	}
	else if (isdigit(input[0]))
	{
		long unsigned int	i = 0;
		while (std::isdigit(input[i]))
			i++;
		if (i == input.length())
			convertInt(input);
		else
			error();
	}
	else
		error();
}