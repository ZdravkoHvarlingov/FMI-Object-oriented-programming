#pragma once

#include "Animal.h"
#include "AnimalFactory.h"

#define MAX_SIZE 10

class Veterinary
{
public:
	Veterinary()
		: count(0)
	{}

	Veterinary(const Veterinary &other) = delete;
	Veterinary& operator=(const Veterinary &other) = delete;

	void AddAnimal(Animal &animal)
	{
		if (count == MAX_SIZE)
		{
			throw "The veterinary is FULL!";
		}

		//Prototype/Clone pattern
		animals[count] = animal.Clone();

		//Factory pattern
		//animals[count] = CopyTheAnimal(animal);
		++count;
	}

	void MakeSymphony() const
	{
		for (size_t i = 0; i < count; i++)	
		{
			animals[i]->MakeNoise();
		}
	}

	~Veterinary()
	{
		for (size_t i = 0; i < count; i++)
		{
			delete animals[i];
		}
	}

private:
	Animal *animals[MAX_SIZE];
	int count;
};
