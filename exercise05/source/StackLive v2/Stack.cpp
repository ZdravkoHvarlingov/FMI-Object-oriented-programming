#include "Stack.h"
#include <algorithm>

#define INITIAL_CAPACITY 4

Stack::Stack()
{
	capacity = INITIAL_CAPACITY;
	elements = new int[capacity];
	size = 0;
}

Stack::Stack(const Stack & other)
{
	CopyHelper(other);
}

void Stack::Push(int element)
{
	if (size == capacity)
	{
		Resize(capacity * 2);
	}

	elements[size] = element;
	++size;
}

void Stack::Pop()
{
	if (size == 0)
	{
		return;
	}

	if (size < capacity / 2)
	{
		Resize(capacity / 2);
	}

	--size;
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
	elements = new int[other.capacity];
	for (int i = 0; i < other.size; ++i)
	{
		elements[i] = other.elements[i];
	}
	size = other.size;
	capacity = other.capacity;
}

void Stack::EraseMemory()
{
	delete[] elements;
}

void Stack::Resize(int newCapacity)
{
	int *temp = new int[newCapacity];

	int newSize = newCapacity < size ? newCapacity : size;
	for (size_t i = 0; i < newSize; i++)
	{
		temp[i] = elements[i];
	}

	size = newSize;
	capacity = newCapacity;
	delete[] elements;
	elements = temp;
}

Stack & Stack::operator=(const Stack &other)
{
	/*std::swap(elements, other.elements);
	std::swap(size, other.size);
	std::swap(capacity, other.capacity);*/

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
