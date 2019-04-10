#pragma once
#include "Aircraft.h"

class AirFreighter : public Aircraft
{
public:
	AirFreighter(double, int, int, int, int, int);

	void IncreaseLuggage(int);

	int GetMaxLuggageCapacity() const;
	int GetCurrentLuggageWeight() const;

private:
	int maxLuggageCapacity;
	int currentLuggage;
};