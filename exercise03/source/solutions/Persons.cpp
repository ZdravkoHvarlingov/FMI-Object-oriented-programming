#include <cstring>
#include <assert.h>
#include <iostream>

class Person
{
public:
	Person(const char *name, const char *familyName, int age, bool isMale);

	const char * GetFirstName();
	const char * GetFamilyName();
	int GetAge();
	bool IsMale();

	void SetAge(int age);
	void SetFirstName(const char *name);
	void SetFamilyName(const char *familyName);

	bool AddChild(Person *prs);
	Person *GetChild(int number);

	bool operator==(Person other);

private:
	char name[128];
	char familyName[128];
	int age;
	bool isMale;

	Person *children[3];
	int childrenNumber;
};

int main()
{
	Person zdravko("Zdravko", "Hvarlingov", 22, 1);
	Person zdravkoJr("ZdravkoJr", "Hvarlingov", 1, 1);

	zdravko.AddChild(&zdravkoJr);
	std::cout << zdravko.GetChild(0)->GetFirstName() << " " << zdravko.GetChild(0)->GetFamilyName() << std::endl;

	std::cout << (zdravko == zdravkoJr) << std::endl;
	std::cout << (zdravko == zdravko) << std::endl;

    return 0;
}

Person::Person(const char * name, const char * familyName, int age, bool isMale)
{
	childrenNumber = 0;
	for (size_t i = 0; i < 3; i++)
	{
		children[i] = nullptr;
	}

	strcpy(this->name, name);
	strcpy(this->familyName, familyName);
	this->age = age;
	this->isMale = isMale;
}

const char * Person::GetFirstName()
{
	return name;
}

const char * Person::GetFamilyName()
{
	return familyName;
}

int Person::GetAge()
{
	return age;
}

bool Person::IsMale()
{
	return isMale;
}

void Person::SetAge(int age)
{
	this->age = age;
}

void Person::SetFirstName(const char * name)
{
	strcpy(this->name, name);
}

void Person::SetFamilyName(const char * familyName)
{
	strcpy(this->familyName, familyName);
}

bool Person::AddChild(Person * prs)
{
	if (childrenNumber == 3)
	{
		return false;
	}

	children[childrenNumber] = prs;
	childrenNumber++;

	return true;
}

Person * Person::GetChild(int number)
{
	if (number < 0 || number >= childrenNumber)
	{
		return nullptr;
	}

	return children[number];
}

bool Person::operator==(Person other)
{
	if (this->childrenNumber != other.childrenNumber)
	{
		return false;
	}

	for (size_t i = 0; i < childrenNumber; i++)
	{
		if (children[i] != other.children[i])
		{
			return false;
		}
	}

	return strcmp(this->name, other.name) == 0 && strcmp(this->familyName, other.familyName) == 0 &&
		this->age == other.age && this->isMale == other.isMale;
}
