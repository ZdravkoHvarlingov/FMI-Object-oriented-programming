#include <iostream>

//using namespace std;

template <typename T>
void Swap(T &fst, T &snd)
{
	T swap = fst;
	fst = snd;
	snd = swap;
}

template <typename T>
int PerformOperation(T fst, T snd, T(*op)(T, T))
{
	return op(fst, snd);
}

int Sum(int fst, int snd)
{
	return fst + snd;
}

int Something(int fst, int snd)
{
	return fst*snd + fst - snd;
}

int main()
{
	int a1 = 10, a2 = 9;

	int(*op)(int, int) = Something;
	std::cout << op(a1, a2) << std::endl;

	std::cout << PerformOperation(a1, a2, Something) << std::endl;

    return 0;
}

