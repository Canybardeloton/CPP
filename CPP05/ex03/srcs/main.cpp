/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:29:18 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/27 14:45:58 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Intern.hpp"

int main()
{
	AForm *form = NULL;
	AForm *form1 = NULL;
	AForm *form2 = NULL;

	try
	{
		Bureaucrat bur1("Arthur", 1);
		Bureaucrat bur2("Diego", 1);
		Bureaucrat bur3("Simon", 1);
		Intern	other;
		std::cout << std::endl;

		std::cout << bur1 << std::endl;
		std::cout << bur2 << std::endl;
		std::cout << bur3 << std::endl;
		std::cout << std::endl;

		form = other.makeForm("Presidential pardon", "Eric");
		form1 = other.makeForm("Shrubbery creation", "Jojo");
		form2 = other.makeForm("Robotomy request", "Manu");
		std::cout << std::endl;

		std::cout << *form << std::endl;
		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << std::endl;

		form->beSigned(bur1);
		form->execute(bur1);
		form1->beSigned(bur2);
		form1->execute(bur2);
		form2->beSigned(bur3);
		form2->execute(bur1);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	if (form)
		delete (form);
	if (form1)
		delete (form1);
	if (form2)
		delete (form2);
	return (0);
}
