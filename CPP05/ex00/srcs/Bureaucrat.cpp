/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:39:33 by agiliber          #+#    #+#             */
/*   Updated: 2025/02/04 12:44:49 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat " << name << " created" << std::endl;
	gradeCheck();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) : _name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << "Bureaucrat " << _name << " created by copy" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & copy)
{
	std::cout << "Bureaucrat " << _name << " assigned" << std::endl;
	_grade = copy.getGrade();
	return (*this);
}

void	Bureaucrat::gradeCheck()
{
	try
	{
		gradeTooHigh();
		gradeTooLow();
	}
	catch (GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::gradeTooHigh()
{
	if (getGrade() < 1)
		throw (GradeTooHighException());
}

void	Bureaucrat::gradeTooLow()
{
	if (getGrade() > 150)
		throw (GradeTooLowException());
}

void	Bureaucrat::increment_grade()
{
	_grade--;
	gradeCheck();
}

void	Bureaucrat::decrement_grade()
{
	_grade++;
	gradeCheck();
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}