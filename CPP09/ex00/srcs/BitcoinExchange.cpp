/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:20:39 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/15 15:28:43 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

BitExch::BitExch(std::string file_search) : _file(file_search)
{
	std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitExch::~BitExch()
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitExch::BitExch(const BitExch& copy) : _file(copy._file)
{
	std::cout << "BitcoinExchange copy called" << std::endl;
}

BitExch&	BitExch::operator=(const BitExch& copy)
{
	if (this != &copy)
	{
		this->_file = copy._file;
		std::cout << "BitcoinExchange copy called" << std::endl;
	}
	return (*this);
}

bool isValidDate(const std::string& date)
{
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	try
	{
		int year = std::atoi(date.substr(0, 4).c_str());
		int month = std::atoi(date.substr(5, 2).c_str());
		int day = std::atoi(date.substr(8, 2).c_str());

		if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
			return (false);
		return (true);
	}
	catch (const std::exception& e)
	{
		return (false);
	}
}

bool	checkHeader(const std::string& line, std::string to_parse)
{
	if (to_parse != " | " && to_parse != ",")
		return (false);
	size_t delimiterPos = line.find(to_parse);
	if (line.substr(0, delimiterPos) != "date")
		return (false);
	size_t len = delimiterPos + to_parse.size();
	if (line.substr(len) != "value" && line.substr(len) != "exchange_rate")
		return (false);
	return (true);
}

bool	parseDataLine(const std::string& line, std::string& date, float& value, std::string to_parse)
{
	size_t delimiterPos = line.find(to_parse);
	if (delimiterPos == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}
	date = line.substr(0, delimiterPos);
	if (!isValidDate(date))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}
	std::string valueStr = line.substr(delimiterPos + to_parse.size());
	try
	{
		value = std::atof(valueStr.c_str());
		if (to_parse == " | ")
		{
			if (value < 0)
			{
				std::cerr << "Error: not a positive number." << std::endl;
				return (false);
			}
			if (value > 1000)
			{
				std::cerr << "Error: too large a number." << std::endl;
				return (false);
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: invalid value format." << std::endl;
		return (false);
	}
	return (true);
}

bool	CheckFile(std::map<std::string, float>& data, std::map<std::string, float>& ref, std::string to_parse, std::string file)
{
	std::string	line;
	std::ifstream	in(file.c_str());
	if (in.bad())
		throw(WrongFileException());
	std::getline(in, line);
	if (checkHeader(line, to_parse) == false)
	{
		std::cerr << "Bad file header" << std::endl;
		return (0);
	}
	while (std::getline(in, line))
	{
		float	value;
		std::string	date;
		if (parseDataLine(line, date, value, to_parse))
		{
			data[date] = value;
			if (to_parse == " | " && !ref.empty())
				matchDate(date, value, ref);
		}
	}
	in.close();
	return (!data.empty());
}

void	matchDate(const std::string& date, float value, std::map<std::string, float>& ref)
{
	std::map<std::string, float>::iterator exact = ref.find(date);
	if (exact != ref.end())
	{
		std::cout << date << " => " << value << " = " << exact->second * value << std::endl;
		return;
	}
	std::map<std::string, float>::iterator it = ref.lower_bound(date);
	if (it != ref.begin() && it != ref.end())
	{
		--it;
		std::cout << date << " => " << value << " = " << it->second * value << std::endl;
	}
	else if (it == ref.begin())
		std::cout << date << " => " << value << " = " << it->second * value << std::endl;
	else
		std::cerr << "Error: no Bitcoin price data available." << std::endl;
}
