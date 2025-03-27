/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:29:18 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/27 14:07:04 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat bur1("Arthur", 1);
		Bureaucrat bur2("Diego", 1);
		Bureaucrat bur3("Simon", 1);

		std::cout << bur1 << std::endl;
		std::cout << bur2 << std::endl;
		std::cout << bur3 << std::endl;

		PresidentialPardonForm pardon("Eric");
		ShrubberyCreationForm shrubbery("Jojo");
		RobotomyRequestForm robotomy("Manu");

		std::cout << pardon << std::endl;
		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;

		pardon.beSigned(bur1);
		pardon.execute(bur1);
		shrubbery.beSigned(bur2);
		shrubbery.execute(bur2);
		robotomy.beSigned(bur3);
		robotomy.execute(bur1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
