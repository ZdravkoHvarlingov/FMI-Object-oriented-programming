#include "Helicopter.h"
#include <iostream>

int main()
{
	Helicopter hl(50, 10000);
	hl.IncreaseFuelAmount(10000);

	std::cout << hl.PerformFlight(10) << std::endl;
	std::cout << hl.GetFuelAmount() << std::endl;

	hl.SetDoors();
	std::cout << hl.PerformFlight(10) << std::endl;
	std::cout << hl.GetFuelAmount() << std::endl;

    return 0;
}

