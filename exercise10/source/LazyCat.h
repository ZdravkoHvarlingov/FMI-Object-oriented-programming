#pragma once

#include "Cat.h"

class LazyCat : public Cat
{
public:
	LazyCat(int age = 0, const char *name = "", const char *kind = "")
		: Cat(age, name, kind)
	{
		strcpy(this->className, "LazyCat");
	}

	void MakeNoise() const
	{
		Animal::MakeNoise();
		std::cout << "Meooooooooow, I am a LAZY CAT with a name: " << GetName() << std::endl;
	}

	virtual Animal *Clone() const
	{
		return new LazyCat(*this);
	}
};