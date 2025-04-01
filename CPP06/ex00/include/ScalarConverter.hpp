/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:34:34 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/01 14:29:58 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <ostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include <cmath>

class ScalarConverter
{
	public:
		static void	convert(std::string input);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & copy);
		ScalarConverter& operator=(ScalarConverter const & copy);
		~ScalarConverter();
};