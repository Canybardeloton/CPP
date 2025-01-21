/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:18:06 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/21 10:46:48 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Dog.hpp"
#include "Cat.hpp"

class Animal
{
	public:
		Animal();
		Animal(const Animal &copy);
		Animal &operator=(const Animal &assign);
		~Animal();
	private:
	protected:
		std::string type;
		std::string sound;
		void	makeSound() const;
		std::string getType() const;
};
