#pragma once
#include "FlyingObject.h"

class Aircraft : public FlyingObject
{
public:
	Aircraft(double, int, int, int, int);

	int GetWingSpan() const;
	int GetNumberOfEngines() const;
	int GetNumberOfWorkingEngines() const;
	int GetFlightMinimumEngines() const;

	void SwitchOfEngine();

private:
	int wingSpan;
	int numberOfEngines;
	int workingEngines;
	int flightMinimumEngines;
};
