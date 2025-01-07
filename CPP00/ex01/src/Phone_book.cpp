/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:32:46 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/02 11:44:19 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phone_book.hpp"

Phone_book::Phone_book() : _index(0) , _last_contact(0)
{
}

Phone_book::~Phone_book()
{
}

void	Phone_book::fill_first_name(Contact& contact_id)
{
	std::string	input;

	std::cout << "--> Please type first name : ";
	std::getline(std::cin, input);
	if (input.empty())
		return ;
	contact_id.set_first_name(input);
	return ;
}

void	Phone_book::fill_last_name(Contact& contact_id)
{
	std::string	input;

	std::cout << "--> Please type last name : ";
	std::getline(std::cin, input);
	if (input.empty())
		return ;
	contact_id.set_last_name(input);
	return ;
}

void	Phone_book::fill_nickname(Contact& contact_id)
{
	std::string	input;

	std::cout << "--> Please type nickname : ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else
	{
		if (input.empty())
			return ;
		contact_id.set_nickname(input);
		return ;
	}
}

void	Phone_book::fill_secret(Contact& contact_id)
{
	std::string	input;

	std::cout << "--> Please type darkest secret : ";
	std::getline(std::cin, input);
	if (input.empty())
		return ;
	contact_id.set_secret(input);
	return ;
}

void	Phone_book::fill_phone_number(Contact& contact_id)
{
	std::string	input;
	std::string	cleaned_number;
	int			i;

	i = 0;
	std::cout << "--> Please type phone_number : ";
	std::getline(std::cin, input);
	if (input.empty())
		return ;
	while(input[i])
	{
		if (isdigit(input[i]))
			cleaned_number += input[i];
		else if (input[i] != ' ' && input[i] != '.')
		{
			std::cout << "Invalid phone number!" << std::endl;
			return;
		}
		i++;
	}
	if (cleaned_number.size() > 10 || cleaned_number.size() < 10)
	{
		std::cout << "Invalid phone number!" << std::endl;
		return;
	}
	contact_id.set_phone_number(cleaned_number);
}

void	Phone_book::fill_phonebook()
{
	Contact& contact_id = _contact[_index];
	static int	round = 0;
	if (_last_contact == 7)
	{
		contact_id = _contact[0];
		_index = 0;
		round = 1;
	}
	while (1)
	{
		if (std::cin.eof())
			return ;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (round == 1)
		{
			contact_id.set_first_name("");
			contact_id.set_last_name("");
			contact_id.set_nickname("");
			contact_id.set_phone_number("");
			contact_id.set_secret("");
		}
		if (contact_id.get_first_name() == "")
			fill_first_name(contact_id);
		else if (contact_id.get_last_name() == "")
			fill_last_name(contact_id);
		else if (contact_id.get_nickname() == "")
			fill_nickname(contact_id);
		else if (contact_id.get_phone_number() == "")
			fill_phone_number(contact_id);
		else if (contact_id.get_secret() == "")
			fill_secret(contact_id);
		else if (_last_contact == 7)
			fill_contact(contact_id);
		if (Contact_filled(contact_id) == 1)
			break ;
	}
	if (_index < 7)
		_index++;
	_last_contact = _index;
	return ;
}

void	Phone_book::fill_contact(Contact& contact_id)
{
	fill_first_name(contact_id);
	fill_last_name(contact_id);
	fill_nickname(contact_id);
	fill_phone_number(contact_id);
	fill_secret(contact_id);
}