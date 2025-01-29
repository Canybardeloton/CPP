#pragma once

#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& copy);
		virtual ~WrongAnimal();
		virtual void    makeSound(void) const;
		WrongAnimal& operator=(WrongAnimal const& rhs);
		std::string getType(void) const;
};