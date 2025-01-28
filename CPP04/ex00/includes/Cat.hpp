/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:29:20 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/21 13:29:22 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &copy);
		Cat &operator=(const Cat &assign);
		virtual ~Cat();
		virtual void makeSound(void) const;
	private:
	protected:
};