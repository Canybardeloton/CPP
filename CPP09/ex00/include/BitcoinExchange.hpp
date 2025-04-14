/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:18:45 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/14 16:34:04 by agiliber         ###   ########.fr       */
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
		BitExch(BitExch& const copy);
		BitExch&	operator=(BitExch& const copy);
		~BitExch();

		bool	CheckInputFile(std::map<std::string, float>& data);
		bool	CheckOutputFile(std::map<std::string, float>& data);
		bool	parseDataLine(const std::string& line, std::string& date, float& value);
		bool	parseDataOutLine(const std::string& line, std::string& date, float& value);
		bool	isValidDate(const std::string& date);

	private :
		std::string	_file;

};
