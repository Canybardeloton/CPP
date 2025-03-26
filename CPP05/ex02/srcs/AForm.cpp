/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:48:23 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/26 17:29:04 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signed(false)
{
	if (signGrade < 1 || execGrade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (signGrade > 150 || execGrade > 150)
		throw (Bureaucrat::GradeTooLowException());
	_signGrade = signGrade;
	_execGrade = execGrade;
	std::cout << "Form " << _name << " created" << std::endl;
}

AForm::AForm(AForm const & copy) : _name(copy.getName()), _signed(copy.isSigned()), _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade())
{
	std::cout << "Form " << _name << " created by copy" << std::endl;
}

AForm& AForm::operator=(AForm const & copy)
{
	_signed = copy.isSigned();
	std::cout << "Form " << _name << " assigned" << std::endl;
	return *this;
}

AForm::~AForm()
{
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

void	AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() >= getSignGrade())
		throw (AForm::GradeTooLowException());
	if (_signed == false)
		_signed = true;
	b.signForm(_name, _signed);
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	if (form.isSigned() == true)
		os << form.getName() << " is signed";
	else
		os << form.getName() << " is not signed";
	return os;
}