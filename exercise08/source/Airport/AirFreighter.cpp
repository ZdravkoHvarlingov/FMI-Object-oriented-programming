#include "AirFreighter.h"

AirFreighter::AirFreighter(double fuelConsumptionPer100km, int crewNumber, int wingSpan, int numberOfEngines,
	int flightMinimumEngines, int maxLuggageCapacity)
	: Aircraft(fuelConsumptionPer100km, crewNumber, wingSpan, numberOfEngines, flightMinimumEngines),
	maxLuggageCapacity(maxLuggageCapacity), currentLuggage(0)
{}

void AirFreighter::IncreaseLuggage(int amount)
{
	currentLuggage += amount;
	currentLuggage %= maxLuggageCapacity + 1;
}

int AirFreighter::GetMaxLuggageCapacity() const
{
	return maxLuggageCapacity;
}

int AirFreighter::GetCurrentLuggageWeight() const
{
	return currentLuggage;
}
