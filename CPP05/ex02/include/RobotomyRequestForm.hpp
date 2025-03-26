/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:44:38 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/26 17:57:19 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>
#include <exception>
#include <ostream>
#include <string>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(Bureaucrat &target);
		RobotomyRequestForm(RobotomyRequestForm const & copy);
		RobotomyRequestForm& operator=(RobotomyRequestForm const & copy);
		virtual ~RobotomyRequestForm();

		void execute(Bureaucrat const & executor) const;

	private:
		Bureaucrat& _target;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& Robotomy);