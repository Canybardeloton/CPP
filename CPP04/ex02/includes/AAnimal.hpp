/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:18:06 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/30 11:08:14 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdlib.h>
#include <iterator>

class AAnimal
{
	protected:
		std::string _type;
	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(const AAnimal& copy);
		virtual ~AAnimal();
		virtual void	makeSound(void) const = 0;
		AAnimal&	operator=(AAnimal const& assign);
		virtual std::string getType(void) const;
		void	setType(std::string type);
};
