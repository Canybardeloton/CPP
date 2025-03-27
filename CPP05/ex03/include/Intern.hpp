/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:26:57 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/27 14:18:43 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <ostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const & copy);
		Intern&	operator=(Intern const & copy);
		~Intern();

		AForm*	makeForm(std::string name, std::string target);

		AForm*	makePardon(std::string target);
		AForm*	makeRobotomy(std::string target);
		AForm*	makeShrubbery(std::string target);

		class FormGeneratorError : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Wrong form name");
				}
		};
};