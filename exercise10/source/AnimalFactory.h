#pragma once
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "LazyCat.h"
#include "Frog.h"
#include <string>

Animal* CopyTheAnimal(Animal *animal)
{
	if (strcmp(animal->GetType(), "Cat") == 0)
	{
		//using copy constructor
		Cat *newCat = new Cat(*((Cat*)animal));

		return newCat;
	}

	//Animal is already an abstract class
	//else if (strcmp(animal->GetType(), "Animal") == 0)
	//{
	//	Animal *newAnimal = new Animal(*((Animal*)animal));

	//	return newAnimal;
	//}

	else if (strcmp(animal->GetType(), "Dog") == 0)
	{
		Dog *newDog = new Dog(*((Dog*)animal));

		return newDog;
	}
	else if (strcmp(animal->GetType(), "Frog") == 0)
	{
		Frog *newDog = new Frog(*((Frog*)animal));

		return newDog;
	}
	else if (strcmp(animal->GetType(), "LazyCat") == 0)
	{
		LazyCat *newDog = new LazyCat(*((LazyCat*)animal));

		return newDog;
	}

	return nullptr;
}