class DynamicArray
{
public:
	DynamicArray();

	void Add(int num);
	int GetAt(int index);
	bool RemoveAt(int index);
	int GetSize();
	int GetMin();
	void PerformOperation(int(*op)(int));

private:
	void ShiftLeft(int index);

	int size;
	int numbers[1000];
};

DynamicArray::DynamicArray()
{
	size = 0;
}

void DynamicArray::Add(int num)
{
	if (size >= 1000)
	{
		return;
	}

	numbers[size] = num;
	++size;
}

int DynamicArray::GetAt(int index)
{
	return numbers[index];
}

bool DynamicArray::RemoveAt(int index)
{
	if (size == 0 || index >= size)
	{
		return false;
	}

	ShiftLeft(index);
	--size;
	return true;
}

int DynamicArray::GetSize()
{
	return size;
}

int DynamicArray::GetMin()
{
	int min = numbers[0];
	for (size_t i = 1; i < size; i++)
	{
		if (numbers[i] < min)
		{
			min = numbers[i];
		}
	}

	return min;
}

void DynamicArray::PerformOperation(int(*op)(int))
{
	for (size_t i = 0; i < size; i++)
	{
		//numbers[i] = numbers[i] % 2;
		numbers[i] = op(numbers[i]);
	}
}

void DynamicArray::ShiftLeft(int index)
{
	if (index >= size)
	{
		return;
	}

	for (size_t i = index; i < size - 1; i++)
	{
		numbers[i] = numbers[i + 1];
	}
}
