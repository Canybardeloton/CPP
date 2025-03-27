/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:44:16 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/27 11:47:49 by agiliber         ###   ########.fr       */
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
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & copy);
		PresidentialPardonForm& operator=(PresidentialPardonForm const & copy);
		virtual ~PresidentialPardonForm();

		virtual void execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& PardonForm);