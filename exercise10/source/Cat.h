#pragma once
#include "Animal.h"

class Cat : public Animal
{
public:
	Cat(int age = 0, const char *name = "", const char *kind = "NONE")
		: Animal(age, name)
	{
		strcpy(this->kind, kind);
		strcpy(this->className, "Cat");
	}

	void MakeNoise() const
	{
		Animal::MakeNoise();
		std::cout << "Meow, I am a lazy cat with a name: " << GetName() << std::endl;
	}

	virtual Animal *Clone() const
	{
		return new Cat(*this);
	}

private:
	char kind[50];
};
