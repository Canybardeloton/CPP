/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:39:02 by agiliber          #+#    #+#             */
/*   Updated: 2024/12/20 13:43:39 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact() : _first_name(""), _last_name(""), _nickname(""), _darkest_secret("")
{
}

Contact::~Contact()
{
}

std::string Contact::get_first_name() const
{
	return(_first_name);
}

std::string Contact::get_last_name() const
{
	return(_last_name);
}

std::string Contact::get_nickname() const
{
	return(_nickname);
}

std::string Contact::get_secret() const
{
	return(_darkest_secret);
}

std::string	Contact::get_phone_number() const
{
	return(_phone_number);
}

void Contact::set_first_name(std::string f_name)
{
	_first_name = f_name;
}

void Contact::set_last_name(std::string l_name)
{
	_last_name = l_name;
}

void Contact::set_nickname(std::string n_name)
{
	_nickname = n_name;
}

void Contact::set_secret(std::string dark_secret)
{
	_darkest_secret = dark_secret;
}

void Contact::set_phone_number(std::string phone_number)
{
	_phone_number = phone_number;
}
