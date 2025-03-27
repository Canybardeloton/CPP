/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:23:56 by agiliber          #+#    #+#             */
/*   Updated: 2025/03/27 14:05:11 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm::AForm("Shrubbery creation", 145, 137), _target(target)
{
	std::cout << "A Shrubbery creation Form directed at " << _target << " has been initiated" << std::endl;
};

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "A Shrubbery creation Form has been destroyed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm::AForm(copy), _target(copy._target)
{
	std::cout << "ShrubberyCreationForm created by copy" << std::endl;
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & copy)
{
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& Shrubbery)
{
	os << "Form : " << Shrubbery.getName() << std::endl;
	os << "Signed : " << Shrubbery.isSigned() << std::endl;
	os << "Sign Grade : " << Shrubbery.getSignGrade() << std::endl;
	os << "Exec Grade : " << Shrubbery.getExecGrade() << std::endl;
	return (os);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string	outfile = this->_target + "_shrubbery";
	std::ofstream	file(outfile.c_str());

	executor.executeForm(*this);
	if (this->isSigned() == false)
		throw(ShrubberyCreationForm::SignedFormException());
	if (executor.getGrade() > this->getExecGrade())
		throw(ShrubberyCreationForm::GradeTooLowException());
	if (!file.is_open())
		throw(ShrubberyCreationForm::OpenFileException());
	file << "       _-_" << std::endl;
	file << "    /~~   ~~\\" << std::endl;
	file << " /~~         ~~\\" << std::endl;
	file << "{               }" << std::endl;
	file << " \\  _-     -_  /" << std::endl;
	file << "   ~  \\ //  ~" << std::endl;
	file << "_- -   | | _- _" << std::endl;
	file << "  _ -  | |   -_" << std::endl;
	file << "      // \\\\" << std::endl;
}