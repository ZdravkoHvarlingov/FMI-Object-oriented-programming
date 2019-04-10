#include "Helicopter.h"

Helicopter::Helicopter(double fuelConsumptionPer100kmWithoutTheDoors, int maxHeight, bool isEmergency, bool hasDoors)
	: FlyingObject(fuelConsumptionPer100kmWithoutTheDoors, 1), maximumHeight(maxHeight), isEmergency(isEmergency), hasDoors(hasDoors)
{
}

bool Helicopter::IsEmergency() const
{
	return isEmergency;
}

int Helicopter::GetMaximumHeight() const
{
	return maximumHeight;
}

void Helicopter::SetEmergency()
{
	isEmergency = true;
}

void Helicopter::RemoveEmergency()
{
	isEmergency = false;
}

void Helicopter::RemoveDoors()
{
	hasDoors = false;
}

void Helicopter::SetDoors()
{
	hasDoors = true;
}

bool Helicopter::PerformFlight(double distance)
{
	if (hasDoors)
	{
		ChangeFuelConsumption(GetFuelConsumption() + 10);
	}

	bool res = FlyingObject::PerformFlight(distance);
	
	if (hasDoors)
	{
		ChangeFuelConsumption(GetFuelConsumption() - 10);
	}

	return res;
}
