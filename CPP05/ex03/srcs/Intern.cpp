/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:33:25 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/27 14:30:31 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "An unfortunate Intern has been constructed" << std::endl;
}

Intern::~Intern()
{
	std::cout << "An unfortunate Intern has been destructed" << std::endl;
}

Intern::Intern(Intern const & copy)
{
	std::cout << "An unfortunate Intern has been copied" << std::endl;
	*this = copy;
}

Intern&	Intern::operator=(Intern const & copy)
{
	if (this != &copy)
	{
	}
	std::cout << "An unfortunate Intern has been copied" << std::endl;
	return (*this);
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	typedef AForm* (Intern::*FormFunction)(std::string);
	FormFunction formgenerator[3] = {&Intern::makePardon, &Intern::makeRobotomy, &Intern::makeShrubbery};
	std::string	form[3] = {"Presidential pardon", "Robotomy request", "Shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (form[i] == name)
		{
			std::cout << "Intern create " << name << "." << std::endl;
			return((this->*formgenerator[i])(target));
		}
	}
	throw (FormGeneratorError());
}

AForm*	Intern::makePardon(std::string target)
{
	AForm*	form = new PresidentialPardonForm(target);
	return (form);
}

AForm*	Intern::makeRobotomy(std::string target)
{
	AForm*	form = new RobotomyRequestForm(target);
	return (form);
}

AForm*	Intern::makeShrubbery(std::string target)
{
	AForm*	form = new ShrubberyCreationForm(target);
	return (form);
}
