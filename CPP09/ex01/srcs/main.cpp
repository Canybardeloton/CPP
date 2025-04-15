/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:30:50 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/15 15:56:16 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error : missing argument" << std::endl;
		return (0);
	}
	if (!checkInput(av[1]))
	{
		std::cerr << "Error : bad argument" << std::endl;
		return (0);
	}
}