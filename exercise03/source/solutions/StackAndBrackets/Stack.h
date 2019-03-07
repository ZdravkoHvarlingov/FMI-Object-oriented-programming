#pragma once

#define MAX_SIZE 1000

template <typename T>
class Stack
{
public:

	Stack();
	bool Push(T element);
	T Pop();
	T Top();
	bool Empty();
	int Size();

private:

	T elements[1000];
	int size;
};

template<typename T>
inline Stack<T>::Stack()
	: size(0)
{
}

template<typename T>
inline bool Stack<T>::Push(T element)
{
	if (size == MAX_SIZE)
	{
		return false;
	}

	elements[size] = element;
	++size;
}

template<typename T>
inline T Stack<T>::Pop()
{
	--size;
	return elements[size];
}

template<typename T>
inline T Stack<T>::Top()
{
	return elements[size - 1];
}

template<typename T>
inline bool Stack<T>::Empty()
{
	return size == 0;
}

template<typename T>
inline int Stack<T>::Size()
{
	return size;
}
