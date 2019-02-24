#include <iostream>

using namespace std;

struct Car
{
	char brandName[128];
	char modelName[128];
	double consumption;
	unsigned int weight;
	unsigned int horsePowers;
	unsigned int numberOfDoors;

	Car()
	{
		strcpy(brandName, "NONE");
		strcpy(modelName, "NONE");
		consumption = 0;
		weight = 0;
		horsePowers = 0;
		numberOfDoors = 0;
	}

	Car(const char *_brandName, const char *_modelName, double _consumption, unsigned int _weight, unsigned int _horsePowers, unsigned int _numberOfDoors)
	{
		strcpy(brandName, _brandName);
		strcpy(modelName, _modelName);
		consumption = _consumption;
		weight = _weight;
		horsePowers = _horsePowers;
		numberOfDoors = _numberOfDoors;
	}

	double GetFuelRequired(unsigned int distance, unsigned int passengers)
	{
		return (distance / 100.0) * (consumption + passengers - 1);
	}

	void Print()
	{
		cout << brandName << " " << modelName << "\nConsumption: " << consumption;
		cout << "\nWeight: " << weight << "\nHorse powers: " << horsePowers << "\nDoors: " << numberOfDoors << '\n';
	}

	bool IsFaster(Car another)
	{
		return ((horsePowers * 1.0) / weight) > ((another.horsePowers * 1.0) / another.weight);
	}
};

Car* FindTheSlowest(Car *cars, int N)
{
	if (N == 0)
	{
		return nullptr;
	}

	Car *slowest = cars;
	for (size_t i = 1; i < N; i++)
	{
		if (slowest->IsFaster(cars[i]))
		{
			slowest = cars + i;
		}
	}

	return slowest;
}

Car *FindTheMostEconomical(Car *cars, int N)
{
	if (N == 0)
	{
		return nullptr;
	}

	Car *mostEconomical = cars;
	for (size_t i = 1; i < N; i++)
	{
		if (mostEconomical->consumption > cars[i].consumption)
		{
			mostEconomical = cars + i;
		}
	}

	return mostEconomical;
}

int main()
{
	int N;
	cin >> N;
	

	//Example input:
	//5
	//Audi A8 15 2000 300 5
	//Peugeot 205 7 1300 55 3
	//Opel Corsa 6 900 40 5
	//BMW E360 20 1300 500 5
	//Toyota Yaris 10 1400 90 5

	Car *cars = new Car[N];
	for (size_t i = 0; i < N; i++)
	{
		char brandName[128];
		char modelName[128];
		double consumption;
		unsigned int weight, horsePowers, numberOfDoors;

		cin >> brandName >> modelName >> consumption >> weight >> horsePowers >> numberOfDoors;
		cars[i] = Car(brandName, modelName, consumption, weight, horsePowers, numberOfDoors);
	}

	Car *slowest = FindTheSlowest(cars, N);
	Car *mostEconomical = FindTheMostEconomical(cars, N);

	slowest->Print();
	mostEconomical->Print();

	delete[] cars;

    return 0;
}