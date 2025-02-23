/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:48:41 by agiliber          #+#    #+#             */
/*   Updated: 2025/02/04 14:14:50 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Bureaucrat;

class Form
{
	public:
		Form(std::string name, int signGrade, int execGrade);
		Form(Form const & copy);
		Form& operator=(Form const & copy);
		void	beSigned(Bureaucrat& b);
		std::string getName() const;
		bool isSigned() const;
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