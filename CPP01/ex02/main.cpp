/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:19:05 by agiliber          #+#    #+#             */
/*   Updated: 2024/12/03 11:42:10 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <memory>
#include <bits/stdc++.h>

int	main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "The address of the string is : " << &string << std::endl;
	std::cout << "The address of the stringPTR is : " << &stringPTR << std::endl;
	std::cout << "The address of the stringREF is : " << &stringREF << std::endl;

	std::cout << "The value of the string is : " << string << std::endl;
	std::cout << "The value of the stringPTR is : " << stringPTR << std::endl;
	std::cout << "The value of the stringREF is : " << stringREF << std::endl;
}