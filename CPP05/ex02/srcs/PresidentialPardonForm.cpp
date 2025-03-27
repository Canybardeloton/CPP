/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:25:23 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/27 14:03:44 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm::AForm("Presidential pardon", 25, 5), _target(target)
{
	std::cout << "A Presidential Pardon Form directed at " << _target << " has been initiated" << std::endl;
};

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "A Presidential Pardon Form has been destroyed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm::AForm(copy), _target(copy._target)
{
	std::cout << "PresidentialPardonForm created by copy" << std::endl;
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & copy)
{
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& PardonForm)
{
	os << "Form : " << PardonForm.getName() << std::endl;
	os << "Signed : " << PardonForm.isSigned() << std::endl;
	os << "Sign Grade : " << PardonForm.getSignGrade() << std::endl;
	os << "Exec Grade : " << PardonForm.getExecGrade() << std::endl;
	return (os);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	executor.executeForm(*this);
	if (this->isSigned() == false)
		throw(PresidentialPardonForm::SignedFormException());
	if (executor.getGrade() > this->getExecGrade())
		throw(PresidentialPardonForm::GradeTooLowException());
	std::cout << "Informs that " << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}