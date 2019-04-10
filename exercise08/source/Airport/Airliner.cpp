#include "Airliner.h"
#include <string>

Airliner::Airliner(double fuelConsumptionPer100km, int crewNumber, int wingSpan, int numberOfEngines, int flightMinimumEngines,
	int maximumNumberOfPassengers, int maxNumberOfSuitcasesPerPerson)
	: Aircraft(fuelConsumptionPer100km, crewNumber, wingSpan, numberOfEngines, flightMinimumEngines),
		maximumNumberOfPassengers(maximumNumberOfPassengers), crrNumberOfPassengers(0), maxNumberOfSuitcasesPerPerson(maxNumberOfSuitcasesPerPerson)
{
}

int Airliner::GetMaximumNumberOfPassengers() const
{
	return 0;
}

int Airliner::GetCrrNumberOfPassengers() const
{
	return 0;
}

void Airliner::AddPassenger(const char *name)
{
	if (crrNumberOfPassengers == maximumNumberOfPassengers)
	{
		return;
	}

	strcpy(passNames[crrNumberOfPassengers], name);
	++crrNumberOfPassengers;
}

//seats starting from 1
const char * Airliner::GetPassengerName(int seat)
{
	--seat;
	if (seat >= crrNumberOfPassengers)
	{
		return nullptr;
	}

	return passNames[seat];
}
