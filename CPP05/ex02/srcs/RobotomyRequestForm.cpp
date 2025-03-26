/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:24:44 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/26 18:12:37 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(Bureaucrat &target) : AForm::AForm("Robotomy request", 72, 45), _target(target)
{

	std::cout << "A Robotomy request Form directed at " << _target << " has been initiated" << std::endl;
};

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "A Robotomy request Form has been destroyed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm::AForm(copy), _target(copy._target)
{
	std::cout << "RobotomyRequestForm created by copy" << std::endl;
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & copy)
{
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& Robotomy)
{
	os << "Form : " << Robotomy.getName() << std::endl;
	os << "Signed : " << Robotomy.isSigned() << std::endl;
	os << "Sign Grade : " << Robotomy.getSignGrade() << std::endl;
	os << "Exec Grade : " << Robotomy.getExecGrade() << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	executor.executeForm(*this);
	if (this->isSigned() == false)
		throw(RobotomyRequestForm::SignedFormException());
	if (executor.getGrade() > this->getExecGrade())
		throw(RobotomyRequestForm::GradeTooLowException());

}