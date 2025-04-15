/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:18:45 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/15 11:47:33 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <algorithm>
#include <map>
#include <cstdlib>

class WrongFileException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("Wrong input file");
		}
};

class BitExch
{
	public :
		BitExch(std::string	file_search);
		BitExch(const BitExch& copy);
		BitExch&	operator=(const BitExch& copy);
		~BitExch();

		void	matchDate(std::map<std::string, float>& input, std::map<std::string, float>& ref);

	private :
		std::string	_file;

};

bool	CheckFile(std::map<std::string, float>& data, std::string to_parse, std::string file);
bool	parseDataLine(const std::string& line, std::string& date, float& value, std::string to_parse);
bool	isValidDate(const std::string& date);
