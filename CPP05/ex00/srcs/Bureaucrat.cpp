/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:39:33 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/26 11:25:23 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	gradeCheck();
	_grade = grade;
	std::cout << "Bureaucrat " << this->_name << " created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name << " destroyed" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) : _name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << "Bureaucrat " << this->_name << " created by copy" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & copy)
{
	std::cout << "Bureaucrat " << this->_name << " assigned" << std::endl;
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
	if (getGrade() > 150)
		throw (GradeTooHighException());
}

void	Bureaucrat::gradeTooLow()
{
	if (getGrade() < 1)
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur)
{
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return os;
}