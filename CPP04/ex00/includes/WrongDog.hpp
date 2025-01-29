/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:14:37 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/29 10:15:31 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
	public:
		WrongDog(void);
		WrongDog(const WrongDog& copy);
		virtual ~WrongDog();
		// METHODS
		virtual void makeSound(void) const;
		// OPERATOR OVERLOAD
		WrongDog& operator=(WrongDog const& rhs);
};