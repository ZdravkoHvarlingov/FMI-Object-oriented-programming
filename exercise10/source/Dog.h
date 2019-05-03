#pragma once
#include "Animal.h"

class Dog : public Animal
{
public:
	Dog(int age = 0, const char *name = "")
		: Animal(age, name)
	{
		strcpy(this->className, "Dog");
	}

	void MakeNoise() const
	{
		Animal::MakeNoise();
		std::cout << "BARK, BARK : " << GetName() << std::endl;
	}

	virtual Animal *Clone() const
	{
		return new Dog(*this);
	}
};
