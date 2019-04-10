#pragma once

#include "FlyingObject.h"

class Helicopter : public FlyingObject
{
public:
	Helicopter(double, int, bool = false, bool = false);

	bool IsEmergency() const;
	int GetMaximumHeight() const;
	
	void SetEmergency();
	void RemoveEmergency();
	void RemoveDoors();
	void SetDoors();

	//method overriding
	bool PerformFlight(double);
private:
	bool isEmergency;
	int maximumHeight;
	bool hasDoors;
};
