#include <iostream>

using namespace std;

struct Smartphone
{
	char brand[128];
	char model[128];
	double displaySize;
	unsigned int price;
	bool isTouchscreen;

	Smartphone()
	{
		strcpy(brand, "");
		strcpy(model, "");
		displaySize = 0;
		price = 0;
		isTouchscreen = true;
	}

	Smartphone(const char *_brand, const char *_model)
		: Smartphone()
	{
		strcpy(brand, _brand);
		strcpy(model, _model);
	}

	Smartphone(const char *_brand, const char *_model, double _displaySize,
		unsigned int _price = 1000, bool _isTouchscreen = true)
		: Smartphone(_brand, _model)
	{
		displaySize = _displaySize;
		price = _price;
		isTouchscreen = _isTouchscreen;
	}

	void Ring()
	{
		cout << "Hello, I am " << brand << " " << model << endl;
	}

	void Print()
	{
		cout << brand << endl << model << endl << displaySize << endl << price << endl << isTouchscreen << endl;
	}

	void DoubleRing(Smartphone s)
	{
		Ring();
		s.Ring();
	}
};


int main()
{
	Smartphone s("Samsung", "S10", 10, 2000, false);
	s.Print();
	s.price = 10;

    return 0;
}

