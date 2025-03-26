/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:48:41 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/26 11:04:11 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	public:
		AForm(std::string name, int signGrade, int execGrade);
		AForm(AForm const & copy);
		AForm& operator=(AForm const & copy);
		virtual void	beSigned(Bureaucrat& b) = 0;
		virtual std::string getName() const;
		virtual bool isSigned() const;

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return ("Form grade is too low");
			}
		};

		virtual ~AForm();
	private:
		virtual int getSignGrade() const;
		virtual int getExecGrade() const;

		std::string const _name;
		bool _signed;
		int _signGrade;
		int _execGrade;
};

std::ostream& operator<<(std::ostream& os, const AForm& Bur); // Output stream operator