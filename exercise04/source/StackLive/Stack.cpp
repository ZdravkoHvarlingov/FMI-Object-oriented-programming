#include "Stack.h"

Stack::Stack()
{
	size = 0;
	elements = nullptr;
}

Stack::Stack(const Stack & other)
{
	CopyHelper(other);
}

void Stack::Push(int element)
{
	int *temp = new int[size + 1];
	for (int i = 0; i < size; ++i)
	{
		temp[i] = elements[i];
	}
	temp[size] = element;
	++size;

	delete[] elements;
	elements = temp;
}

void Stack::Pop()
{
	if (size == 0)
	{
		return;
	}

	int *temp = new int[size - 1];
	for (int i = 0; i < size - 1; ++i)
	{
		temp[i] = elements[i];
	}

	--size;
	delete[] elements;
	elements = temp;
}

int Stack::Top() const
{
	return elements[size - 1];
}

int Stack::Size() const
{
	return size;
}

bool Stack::IsEmpty() const
{
	return (size == 0);
}

void Stack::CopyHelper(const Stack & other)
{
	elements = new int[other.size];
	for (int i = 0; i < other.size; ++i)
	{
		elements[i] = other.elements[i];
	}
	size = other.size;
}

void Stack::EraseMemory()
{
	delete[] elements;
}

Stack & Stack::operator=(const Stack & other)
{
	if (this != &other)
	{
		EraseMemory();
		CopyHelper(other);
	}

	//(obj1 = obj2) = obj3;
	return *this;
}

Stack::~Stack()
{
	EraseMemory();
}
