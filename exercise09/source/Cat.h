#pragma once
#include "Animal.h"

class Cat : public Animal
{
public:
	Cat(int age = 0, const char *name = "", const char *kind = "NONE")
		: Animal(age, name)
	{
		strcpy(this->kind, kind);
	}

	void MakeNoise() const
	{
		std::cout << "Meow, I am a lazy cat with a name: " << GetName() << std::endl;
	}

private:
	char kind[50];
};
