/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:03:01 by agiliber          #+#    #+#             */
/*   Updated: 2024/12/09 13:28:59 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"

Sed::Sed()
{
	std::cout << "Sed is constructed" << std::endl;
}

Sed::~Sed()
{
	std::cout << "Sed is destroyed" << std::endl;
}

void	Sed::open_copy(char	**av)
{
	std::ifstream	infile(av[1]);
	if (!infile)
	{
		std::cerr << "Cannot open input file " << av[1] << std::endl;
		return;
	}
	std::string		file = av[1];
	std::string		of = file + ".replace";
	std::ofstream	outfile(of.c_str());
	if (!outfile)
	{
		std::cerr << "Error: Cannot open output file " << of << std::endl;
		return;
	}
	std::string		input;
	std::string		line;
	std::string		final_str;
	while (getline(infile, line))
		input += line + '\n';
	final_str = string_match(input, av[2], av[3]);
	outfile << final_str;
	infile.close();
	outfile.close();
}

std::string		Sed::string_match(std::string full_str, std::string s1, std::string s2)
{
	size_t	y = 0;
	size_t	z = 0;
	std::string	final_str;

	if (s1.empty())
		return (full_str);
	while ((y = full_str.find(s1, z)) != std::string::npos)
	{
		final_str += full_str.substr(z, y - z);
		final_str += s2;
		z = y + s1.length();
	}
	final_str += full_str.substr(z);
	return (final_str);
}
