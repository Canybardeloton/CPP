/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:29:30 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/21 13:23:13 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &copy);
		Dog &operator=(const Dog &assign);
		virtual ~Dog();
		virtual void makeSound(void) const;
	private:
	protected:
};