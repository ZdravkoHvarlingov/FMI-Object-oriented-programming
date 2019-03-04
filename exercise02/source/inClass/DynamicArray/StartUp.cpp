#include <iostream>
#include "DynamicArray.h"

int IsEvenTransformation(int num)
{
	return num % 2;
}

int main()
{
	DynamicArray arr;
	for (size_t i = 0; i < 10; i++)
	{
		arr.Add(i);
	}

	for (size_t i = 0; i < arr.GetSize(); i++)
	{
		std::cout << arr.GetAt(i) << " ";
	}
	std::cout << std::endl;

	arr.PerformOperation(IsEvenTransformation);
	for (size_t i = 0; i < arr.GetSize(); i++)
	{
		std::cout << arr.GetAt(i) << " ";
	}
	std::cout << std::endl;
}