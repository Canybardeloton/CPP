/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:44:16 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/26 18:01:04 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>
#include <exception>
#include <ostream>
#include <string>

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(Bureaucrat &target);
		PresidentialPardonForm(PresidentialPardonForm const & copy);
		PresidentialPardonForm& operator=(PresidentialPardonForm const & copy);
		virtual ~PresidentialPardonForm();

		void execute(Bureaucrat const & executor) const;

	private:
		Bureaucrat& _target;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& PardonForm);