#pragma once

#include <string>
#include <iostream>

class Animal
{
public:
	Animal(int age = 0, const char *name = "DEFAULT")
	{
		this->age = age;
		strcpy(this->name, name);
	}

	virtual void MakeNoise() const
	{
		std::cout << "Just a normal animal, NO NOISE :(" << std::endl;
	}

	const char* GetName() const
	{
		return name;
	}

	int GetAge() const
	{
		return age;
	}

private:
	char name[100];
	int age;
};
