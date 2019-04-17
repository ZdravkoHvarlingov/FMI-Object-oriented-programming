#pragma once
#include "Animal.h"

class Dog : public Animal
{
public:
	Dog(int age = 0, const char *name = "")
		: Animal(age, name)
	{}

	void MakeNoise() const
	{
		std::cout << "BARK, BARK : " << GetName() << std::endl;
	}
};
