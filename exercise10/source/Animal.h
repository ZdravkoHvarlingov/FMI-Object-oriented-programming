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
		strcpy(this->className, "Animal");
	}

	virtual void MakeNoise() const
	{
		std::cout << "My class name is: " << className << std::endl;
	}

	const char* GetName() const
	{
		return name;
	}

	int GetAge() const
	{
		return age;
	}

	const char* GetType() const
	{
		return className;
	}

	virtual Animal *Clone() const = 0;

	virtual ~Animal()
	{}

protected:
	char className[100];

private:
	char name[100];
	int age;
};
