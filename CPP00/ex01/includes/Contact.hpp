/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:03:00 by agiliber          #+#    #+#             */
/*   Updated: 2024/12/19 15:12:47 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <string>
# include <iostream>
# include <ctype.h>
# include <stdio.h>

class Contact
{
	public :
		Contact();
			// GET VALUES
			std::string	get_first_name() const;
			std::string	get_last_name() const;
			std::string	get_nickname()const;
			std::string	get_phone_number() const;
			std::string	get_secret()const;

			// SET VALUES
			void	set_first_name(std::string f_name);
			void	set_last_name(std::string l_name);
			void	set_nickname(std::string n_name);
			void	set_phone_number(std::string phone_number);
			void	set_secret(std::string dark_secret);
		~Contact();

	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
};

#endif
