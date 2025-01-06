/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phone_book_utils.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:00:44 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/02 11:43:06 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phone_book.hpp"

bool	Phone_book::Contact_filled(Contact& contact_id)
{
	int	trigger = 0;

	if (contact_id.get_first_name() != "")
		trigger++;
	if (contact_id.get_last_name() != "")
		trigger++;
	if (contact_id.get_nickname() != "")
		trigger++;
	if (contact_id.get_phone_number() != "")
		trigger++;
	if (contact_id.get_secret() != "")
		trigger++;
	if (trigger == 5)
		return (1);
	else
		return (0);
}

void Phone_book::print_first_name(Contact& contact_id)
{
	int			i = 0;
	int			y = 0;
	std::string	input;
	int			size;

	input = contact_id.get_first_name();
	size = input.size();
	if (size < 10)
	{
		while (i < 10 - size)
		{
			std::cout << " ";
			i++;
		}
	}
	while (i + y < 9 && input[y])
	{
		std::cout << input[y];
		y++;
	}
	if (input[y] && input[y  + 1] != '\0')
		std::cout << ".";
	else
		std::cout << input[y];
	std::cout << "|";
	return ;
}

void Phone_book::print_last_name(Contact& contact_id)
{
	int			i = 0;
	int			y = 0;
	std::string	input;
	int			size;

	input = contact_id.get_last_name();
	size = input.size();
	if (size < 10)
	{
		while (i < 10 - size)
		{
			std::cout << " ";
			i++;
		}
	}
	while (i + y < 9 && input[y])
	{
		std::cout << input[y];
		y++;
	}
	if (input[y] && input[y  + 1] != '\0')
		std::cout << ".";
	else
		std::cout << input[y];
	std::cout << "|";
	return ;
}

void Phone_book::print_nickname(Contact& contact_id)
{
	int			i = 0;
	int			y = 0;
	std::string	input;
	int			size;

	input = contact_id.get_nickname();
	size = input.size();
	if (size < 10)
	{
		while (i < 10 - size)
		{
			std::cout << " ";
			i++;
		}
	}
	while (i + y < 9 && input[y])
	{
		std::cout << input[y];
		y++;
	}
	if (input[y] && input[y  + 1] != '\0')
		std::cout << ".";
	else
		std::cout << input[y];
	return ;
}

int	Phone_book::string_to_int(std::string str)
{
	int	num;

	std::istringstream(str) >> num;
	return (num);
}

std::string	Phone_book::int_to_string(int num)
{
	std::ostringstream	string;

	string << num;
	return (string.str());
}

void Phone_book::print_contact()
{
	int			index;
	std::string	input;
	int			i;

	index = 0;
	std::cout << "--> Please type contact index : ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	else
	{
		if (input.empty())
		{
			std::cout << "Index cannot be empty!" << std::endl;
			return;
		}
		index = string_to_int(input);
		if (index < 0 || index > 7)
		{
			std::cout << "No contact at this index" << std::endl;
			return ;
		}
		Contact& contact_id = _contact[index];
		std::cout << "    Index | First n. | Last na. | Nickname " << std::endl;
		std::cout << "        " << index << " |";
		this->print_first_name(contact_id);
		this->print_last_name(contact_id);
		this->print_nickname(contact_id);
		std::cout << std::endl;
	}
}
