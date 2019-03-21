#define DEFAULT_SIZE 32

class DynamicArray
{
public:
	DynamicArray(int N = DEFAULT_SIZE);
	DynamicArray(const DynamicArray &other);

	void Add(int num);
	int GetAt(int index) const;
	bool RemoveAt(int index);
	int GetSize() const;
	int GetMin() const;
	void PerformOperation(int(*op)(int));
	
	DynamicArray operator+(DynamicArray other);
	operator int();
	int& operator[](int index);
	int operator[](int index) const;
	DynamicArray& operator=(const DynamicArray &other);

	~DynamicArray();
private:
	void ShiftLeft(int index);
	void Resize(int newCapacity);

	int size;
	int capacity;
	int *numbers;
};

DynamicArray::DynamicArray(int N)
	: size(0), capacity(N)
{
	numbers = new int[N];
}

inline DynamicArray::DynamicArray(const DynamicArray & other)
{
	numbers = new int[other.capacity];
	size = other.size;
	capacity = other.capacity;

	for (size_t i = 0; i < other.size; i++)
	{
		numbers[i] = other.numbers[i];
	}
}

int& DynamicArray::operator[](int index)
{
	return numbers[index];
}

inline int DynamicArray::operator[](int index) const
{
	return numbers[index];
}

inline DynamicArray & DynamicArray::operator=(const DynamicArray & other)
{
	if (&other == this)
	{
		return *this;
	}

	delete[] numbers;
	numbers = new int[other.capacity];
	size = other.size;
	capacity = other.capacity;

	for (size_t i = 0; i < other.size; i++)
	{
		numbers[i] = other.numbers[i];
	}

	return *this;
}

void DynamicArray::Add(int num)
{
	if (size == capacity)
	{
		Resize(capacity * 2);
	}

	numbers[size] = num;
	++size;
}

int DynamicArray::GetAt(int index) const
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

int DynamicArray::GetSize() const
{
	return size;
}

int DynamicArray::GetMin() const
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

DynamicArray DynamicArray::operator+(DynamicArray other)
{
	DynamicArray res;
	for (size_t i = 0; i < size; i++)
	{
		res.Add(numbers[i]);
	}

	for (size_t i = 0; i < other.size; i++)
	{
		res.Add(other.numbers[i]);
	}

	return res;
}

DynamicArray::operator int()
{
	int sum = 0;
	/*for (size_t i = 0; i < this->GetSize(); i++)
	{
		sum += this->GetAt(i);
	}*/
	for (size_t i = 0; i < size; i++)
	{
		sum += numbers[i];
	}

	return sum;
}

inline DynamicArray::~DynamicArray()
{
	delete[] numbers;
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

inline void DynamicArray::Resize(int newCapacity)
{
	int *newArray = new int[newCapacity];
	int newSize = newCapacity < size ? newCapacity : size;

	for (size_t i = 0; i < newSize; i++)
	{
		newArray[i] = numbers[i];
	}
	size = newSize;
	capacity = newCapacity;
	
	delete[] numbers;
	numbers = newArray;
}
