#include "FlyingObject.h"
#include <string>

FlyingObject::FlyingObject(double fuelConsumptionPer100km, int crewNumber)
	: fuelConsumptionPer100km(fuelConsumptionPer100km), crewNumber(crewNumber), fuelAmount(0)
{
	strcpy(captainName, "");
}

void FlyingObject::IncreaseFuelAmount(double amount)
{
	fuelAmount += amount;
}

double FlyingObject::GetFuelAmount() const
{
	return fuelAmount;
}

double FlyingObject::GetFuelConsumption() const
{
	return fuelConsumptionPer100km;
}

void FlyingObject::SetCaptainName(const char *captainName)
{
	strcpy(this->captainName, captainName);
}

const char * FlyingObject::GetCaptainName() const
{
	return captainName;
}

int FlyingObject::GetCrewNumber() const
{
	return crewNumber;
}

bool FlyingObject::PerformFlight(double distance)
{
	double requiredFuel = (distance / 100) * fuelConsumptionPer100km;
	if (requiredFuel > fuelAmount)
	{
		return false;
	}

	//Do smth special

	fuelAmount -= requiredFuel;
	return true;
}

void FlyingObject::ChangeFuelConsumption(int newValue)
{
	if (newValue > 0)
	{
		fuelConsumptionPer100km = newValue;
	}
}
