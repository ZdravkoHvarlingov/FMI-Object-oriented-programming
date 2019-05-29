#include <iostream>
#include "Tree.h"

class IntWrapper
{
public:
	IntWrapper()
	{
		number = 1;
	}

	IntWrapper operator+(IntWrapper &other)
	{
		IntWrapper res;
		res.number = number + other.number;

		return res;
	}

	int GetNum() const
	{
		return number;
	}

private:
	int number;
};



int main()
{
	Tree<IntWrapper> zeroTree;
	++zeroTree;
	++zeroTree;
	++zeroTree;

	std::cout << zeroTree.GetRows() << std::endl;
	std::cout << zeroTree.GetAt(1, 1).GetNum() << std::endl;
    return 0;
}

