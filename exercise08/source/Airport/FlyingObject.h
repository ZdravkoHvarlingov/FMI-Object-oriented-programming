#pragma once

class FlyingObject
{
public:
	FlyingObject(double, int);

	void IncreaseFuelAmount(double);
	double GetFuelAmount() const;
	double GetFuelConsumption() const;
	void SetCaptainName(const char*);
	const char* GetCaptainName() const;
	int GetCrewNumber() const;
	bool PerformFlight(double);

protected:
	void ChangeFuelConsumption(int);

private:
	double fuelAmount;
	double fuelConsumptionPer100km;
	int crewNumber;
	char captainName[100];
};
