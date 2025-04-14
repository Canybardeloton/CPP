/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:20:39 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/14 16:34:50 by agiliber         ###   ########.fr       */
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

BitExch::BitExch(BitExch& const copy) : _file(copy._file)
{
	std::cout << "BitcoinExchange copy called" << std::endl;
}

BitExch&	BitExch::operator=(BitExch& const copy)
{
	if (this != &copy)
	{
		this->_file = copy._file;
		std::cout << "BitcoinExchange copy called" << std::endl;
	}
	return (*this);
}

bool BitExch::isValidDate(const std::string& date)
{
	if (date.length() != 10) {
		return false;
	}
	if (date[4] != '-' || date[7] != '-') {
		return false;
	}

	try {
		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));

		if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
			return false;
		}
		return true;
	}
	catch (const std::exception& e) {
		return false;
	}
}

bool	BitExch::parseDataLine(const std::string& line, std::string& date, float& value)
{
	size_t delimiterPos = line.find(",");
	if (delimiterPos == std::string::npos)
		return false;
	date = line.substr(0, delimiterPos);
	if (!isValidDate(date))
	{
		std::cerr << "Wrong date" << std::endl;
		return false;
	}
	std::string valueStr = line.substr(delimiterPos + 1);
	try
	{
		value = std::stof(valueStr);
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			return false;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			return false;
		}
		return true;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: invalid value format." << std::endl;
		return false;
	}
}

bool	BitExch::CheckInputFile(std::map<std::string, float>& data)
{
	std::string	line;
	std::ifstream	in(this->_file);
	if (in.bad())
		throw(WrongFileException());
	while (std::getline(in, line))
	{
		float	value;
		std::string	date;
		if (parseDataLine(line, date, value))
		{
			data[date] = value;
		}
	}
	in.close();
	return (!data.empty());
}

bool	BitExch::parseDataOutLine(const std::string& line, std::string& date, float& value)
{
	size_t delimiterPos = line.find(" | ");
	if (delimiterPos == std::string::npos)
		return false;
	date = line.substr(0, delimiterPos);
	if (!isValidDate(date))
	{
		std::cerr << "Wrong date" << std::endl;
		return false;
	}
	std::string valueStr = line.substr(delimiterPos + 3);
	try
	{
		value = std::stof(valueStr);
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			return false;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			return false;
		}
		return true;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: invalid value format." << std::endl;
		return false;
	}
}

bool	BitExch::CheckOutputFile(std::map<std::string, float>& data)
{
	std::string	line;
	std::ifstream	in(this->_file);
	if (in.bad())
		throw(WrongFileException());
	while (std::getline(in, line))
	{
		float	value;
		std::string	date;
		if (parseDataLine(line, date, value))
		{
			data[date] = value;
		}
	}
	in.close();
	return (!data.empty());
}