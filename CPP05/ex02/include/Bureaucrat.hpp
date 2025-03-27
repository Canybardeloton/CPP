/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:34:34 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/27 14:01:06 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <ostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & copy);
		Bureaucrat& operator=(Bureaucrat const & copy);
		void	increment_grade();
		void	decrement_grade();
		int getGrade() const;
		void	signForm(const std::string name, bool sign);
		void	executeForm(AForm const & form) const;
		std::string getName() const;
		~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade is too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade is too low");
				}
		};
	private:

		void	gradeTooHigh(void);
		void	gradeTooLow(void);

		std::string const _name;
		int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bur);