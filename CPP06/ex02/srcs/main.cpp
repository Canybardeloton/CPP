/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:22:52 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/02 10:25:24 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

Base * generate(void)
{
	int	num;
	srand(time(NULL));

	num = std::rand() % 3;
	if (num == 0)
	{
		Base *base = new A();
		return (base);
	}
	else if (num == 1)
	{
		Base *base = new B();
		return (base);
	}
	else
	{
		Base *base = new C();
		return (base);
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "The base is of type A." << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "The base is of type B." << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "The base is of type C." << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& baseA = dynamic_cast<A&>(p);
		(void) baseA;
		std::cout << "The base is of type A." << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B& baseB = dynamic_cast<B&>(p);
		(void) baseB;
		std::cout << "The base is of type B." << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C& baseC = dynamic_cast<C&>(p);
		(void) baseC;
		std::cout << "The base is of type C." << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}

int	main()
{
	Base *	ptr = generate();

	identify(ptr);
	identify(*ptr);

	delete ptr;

	return 0;
}