#include <vector>
#include <iostream>

class Property
{
public:
	virtual bool test(int *a, int n) = 0;

	virtual ~Property()
	{}
};

class DivisiblyBy : public Property
{
public:
	DivisiblyBy(int x)
		: x(x)
	{}

	virtual bool test(int *a, int n) override
	{
		for (size_t i = 0; i < n; i++)
		{
			if (a[i] % x != 0)
			{
				return false;
			}
		}

		return true;
	}

private:
	int x;
};

class CountNumbers : public Property
{
public:
	CountNumbers(int x, int k)
		: x(x), k(k)
	{}

	virtual bool test(int *a, int n) override
	{
		int count = 0;
		for (size_t i = 0; i < n; i++)
		{
			if (a[i] == x)
			{
				++count;
			}
		}

		return count == k;
	}

private:
	int x, k;
};

class Properties
{
public:
	void Add(Property *prop)
	{
		properties.push_back(prop);
	}

	bool TestAll(int *a, int n)
	{
		for (size_t i = 0; i < properties.size(); i++)
		{
			if (properties[i]->test(a, n) == false)
			{
				return false;
			}
		}

		return true;
	}

private:
	std::vector<Property*> properties;
};


int main()
{
	DivisiblyBy prop1(10);
	CountNumbers prop2(10, 3);

	Properties props;
	props.Add(&prop1);
	props.Add(&prop2);

	int a[] = { 10, 10, 20, 30 };
	std::cout << props.TestAll(a, 4) << std::endl;

    return 0;
}

