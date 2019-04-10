#pragma once

#include "Aircraft.h"

class Airliner : public Aircraft
{
public:
	Airliner(double, int, int, int, int, int, int);

	int GetMaximumNumberOfPassengers() const;
	int GetCrrNumberOfPassengers() const;
	void AddPassenger(const char*);
	const char* GetPassengerName(int);

private:
	int maximumNumberOfPassengers;
	int crrNumberOfPassengers;
	char passNames[500][100];
	int maxNumberOfSuitcasesPerPerson;
};