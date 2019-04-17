#pragma once

#include "Animal.h"

#define MAX_SIZE 10

class Veterinary
{
public:
	Veterinary()
		: count(0)
	{}

	void AddAnimal(Animal *animal)
	{
		if (animal == nullptr)
		{
			throw "Invalid ANIMAL!";
		}

		if (count == MAX_SIZE)
		{
			throw "The veterinary is FULL!";
		}

		animals[count] = animal;
		++count;
	}

	void MakeSymphony() const
	{
		for (size_t i = 0; i < count; i++)
		{
			animals[i]->MakeNoise();
		}
	}

private:
	Animal *animals[MAX_SIZE];
	int count;
};
