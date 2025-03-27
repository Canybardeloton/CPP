/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:43:21 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/27 09:37:41 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>
#include <exception>
#include <ostream>
#include <string>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(Bureaucrat &target);
		ShrubberyCreationForm(ShrubberyCreationForm const & copy);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const & copy);
		virtual ~ShrubberyCreationForm();

		virtual void execute(Bureaucrat const & executor) const;

	private:
		Bureaucrat& _target;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& Shrubbery);