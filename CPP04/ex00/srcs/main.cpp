/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:30:44 by agiliber          #+#    #+#             */
/*   Updated: 2025/01/29 10:22:13 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongDog.hpp"

int main()
{
	const Animal* meta = new Animal();

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	delete meta;
	delete j;
	delete i;


	const WrongAnimal* meto = new WrongAnimal();
	const WrongAnimal* k = new WrongDog();
	std::cout << meto->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	meto->makeSound();
	k->makeSound(); //will output the Wrongcat sound!
	delete meto;
	delete k;

	return 0;
}