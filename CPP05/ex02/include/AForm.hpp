/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:48:41 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/26 18:23:02 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm(std::string name, int signGrade, int execGrade);
		AForm(AForm const & copy);
		AForm& operator=(AForm const & copy);
		void	beSigned(Bureaucrat& b);
		std::string getName() const;
		bool isSigned() const;

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return ("Form grade is too low");
			}
		};

		class SignedFormException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return ("Form is not signed");
			}
		};

		class OpenFileException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return ("Error: Can't open the file");
			}
		};

		virtual void	execute(Bureaucrat const & executor) = 0;
		virtual ~AForm();

		int getSignGrade() const;
		int getExecGrade() const;

	private:
		std::string const _name;
		bool _signed;
		int _signGrade;
		int _execGrade;
};

std::ostream& operator<<(std::ostream& os, const AForm& Bur);