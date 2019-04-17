#pragma once
#include "Animal.h"

class Frog : public Animal
{
public:
	Frog(int age = 0, const char *name = "")
		: Animal(age, name)
	{}

	void MakeNoise() const
	{
		std::cout << "KWAAK, I am a crazy FROG with a name: " << GetName() << std::endl;
	}
};
