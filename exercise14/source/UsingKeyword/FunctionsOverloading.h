#pragma once
#include <iostream>

struct Pair
{
	int x, y;
};

class Person
{
public:
	virtual void SaySomething(int number)
	{
		std::cout << number << std::endl;
	}
	void SaySomething(Pair p)
	{
		std::cout << p.x << " " << p.y << std::endl;
	}
};

class Worker : public Person
{
public:
	//When we define a method with the same name as one in the base class => all from the base class with this name are hidden in the derived;
	//Unless we include them explicitly
	using Person::SaySomething;
	bool SaySomething(const char *text)
	{
		std::cout << text << std::endl;

		return true;
	}
};
