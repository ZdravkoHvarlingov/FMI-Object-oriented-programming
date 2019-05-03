#pragma once
#include "Animal.h"

class Frog : public Animal
{
public:
	Frog(int age = 0, const char *name = "")
		: Animal(age, name)
	{

		strcpy(this->className, "Frog");
	}

	void MakeNoise() const
	{
		Animal::MakeNoise();

		std::cout << "KWAAK, I am a crazy FROG with a name: " << GetName() << std::endl;
	}

	virtual Animal *Clone() const
	{
		return new Frog(*this);
	}
};
