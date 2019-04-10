#include "Aircraft.h"

Aircraft::Aircraft(double fuelConsumptionPer100km, int crewNumber, int wingSpan, int numberOfEngines, int flightMinimumEngines)
	: FlyingObject(fuelConsumptionPer100km, crewNumber),
	wingSpan(wingSpan), numberOfEngines(numberOfEngines), flightMinimumEngines(flightMinimumEngines), workingEngines(numberOfEngines)
{}

int Aircraft::GetWingSpan() const
{
	return wingSpan;
}

int Aircraft::GetNumberOfEngines() const
{
	return numberOfEngines;
}

int Aircraft::GetNumberOfWorkingEngines() const
{
	return workingEngines;
}

int Aircraft::GetFlightMinimumEngines() const
{
	return flightMinimumEngines;
}

void Aircraft::SwitchOfEngine()
{
	if (workingEngines > 0)
	{
		--workingEngines;
	}
}
