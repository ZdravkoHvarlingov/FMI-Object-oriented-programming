#include <iostream>
#include "DynamicArray.h"

int IsEvenTransformation(int num)
{
	return num % 2;
}

int MultiplyBy2(int num)
{
	return num * 2;
}

//int temp = 20;

int main()
{
	DynamicArray arr1(3);
	for (size_t i = 0; i < 5; i++)
	{
		arr1.Add(i);
	}

	DynamicArray arr2 = arr1;
	arr1[0] = 10;
	for (size_t i = 0; i < arr2.GetSize(); i++)
	{
		std::cout << arr2[i] << std::endl;
	}
}