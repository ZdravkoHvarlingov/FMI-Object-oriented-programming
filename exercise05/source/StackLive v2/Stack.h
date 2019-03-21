#pragma once

class Stack
{
public:
	Stack();
	Stack(const Stack &other);

	void Push(int element);
	void Pop();
	int Top() const;
	int Size() const;
	bool IsEmpty() const;

	Stack& operator=(const Stack &other);

	~Stack();

private:

	void CopyHelper(const Stack &other);
	void EraseMemory();
	void Resize(int newCapacity);

	int *elements;
	int size, capacity;
};
