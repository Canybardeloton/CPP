/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:03:00 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/02 11:20:50 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

# include "Contact.hpp"
# include <sstream>
# include <limits>

class Phone_book
{
	public:
		Phone_book();
			void		fill_first_name(Contact& contact_id);
			void		fill_last_name(Contact& contact_id);
			void		fill_nickname(Contact& contact_id);
			void		fill_secret(Contact& contact_id);
			void		fill_phone_number(Contact& contact_id);
			void		fill_phonebook();
			bool		Contact_filled(Contact& contact_id);
			void		print_contact();
			void		print_first_name(Contact& contact_id);
			void		print_last_name(Contact& contact_id);
			void		print_nickname(Contact& contact_id);
			int			string_to_int(std::string str);
			void		fill_contact(Contact& contact_id);
			std::string	int_to_string(int num);
		~Phone_book();
	private :
		Contact	_contact[8];
		int		_index;
		int		_last_contact;
};

#endif
