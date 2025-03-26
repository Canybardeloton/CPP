/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:48:23 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/26 16:05:59 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _execGrade(execGrade)
{
	if (signGrade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (signGrade > 150)
		throw (Bureaucrat::GradeTooLowException());
	_signGrade = signGrade;
	std::cout << "Form " << _name << " created" << std::endl;
}

Form::Form(Form const & copy) : _name(copy.getName()), _signed(copy.isSigned()), _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade())
{
	std::cout << "Form " << _name << " created by copy" << std::endl;
}

Form& Form::operator=(Form const & copy)
{
	_signed = copy.isSigned();
	std::cout << "Form " << _name << " assigned" << std::endl;
	return *this;
}

Form::~Form()
{
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _signed;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecGrade() const
{
	return _execGrade;
}

void	Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() >= getSignGrade())
		throw (Form::GradeTooLowException());
	if (_signed == false)
		_signed = true;
	else
		std::cout << b.getName() << " can't sign the form. The form is already signed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	if (form.isSigned() == true)
		os << form.getName() << " is signed";
	else
		os << form.getName() << " is not signed";
	return os;
}