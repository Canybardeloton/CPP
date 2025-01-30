/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:30:44 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/30 11:10:31 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main()
{
	AAnimal* animals[50];

	for (int i = 0; i < 25; i++)
		animals[i] = new Cat();
	for (int i = 0; i < 25; i++)
		animals[i]->makeSound();
	for (int i = 25; i < 50; i++)
		animals[i] = new Dog();
	for (int i = 25; i < 50; i++)
		animals[i]->makeSound();

	for (size_t i = 0; i < 50; i++)
		delete animals[i];

	return 0;
}