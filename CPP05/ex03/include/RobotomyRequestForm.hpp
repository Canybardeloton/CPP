/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:44:38 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/27 11:47:52 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>
#include <ctime>
#include <exception>
#include <ostream>
#include <string>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & copy);
		RobotomyRequestForm& operator=(RobotomyRequestForm const & copy);
		virtual ~RobotomyRequestForm();

		virtual void execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& Robotomy);