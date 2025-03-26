/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:48:41 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/26 18:03:31 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form(std::string name, int signGrade, int execGrade);
		Form(Form const & copy);
		Form& operator=(Form const & copy);
		void	beSigned(Bureaucrat& b);
		std::string getName() const;
		bool isSigned() const;

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return ("Bureaucrat grade is too low");
			}
		};
		~Form();
	private:
		int getSignGrade() const;
		int getExecGrade() const;

		std::string const _name;
		bool _signed;
		int _signGrade;
		int _execGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& Bur); // Output stream operator