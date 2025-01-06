/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:14:10 by agiliber          #+#    #+#             */
/*   Updated: 2024/12/20 17:07:22 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phone_book.hpp"

int	welcome_message()
{
	std::cout << "Please type a command : ";
	return (0);
}

int	main()
{
	std::string	input;
	Phone_book	rep;

	while (!(std::cin.eof()))
	{
		welcome_message();
		std::getline(std::cin, input);
		if (input.empty())
			continue;
		else if (input == "ADD")
			rep.fill_phonebook();
		else if (input == "SEARCH")
			rep.print_contact();
		else if (input == "EXIT")
			return (0);
	}
	return (0);
}