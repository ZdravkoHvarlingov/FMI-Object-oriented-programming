#include "LinkedList.h"
#include <iostream>

int main()
{
	LinkedList list;
	list.PushEnd(1);
	list.PushEnd(2);
	list.PushEnd(3);

	for (size_t i = 0; i < list.Size(); i++)
	{
		std::cout << list.GetAt(i) << " ";
	}
	std::cout << std::endl;

	LinkedList snd = list;

	snd.PushFront(4);
	for (size_t i = 0; i < list.Size(); i++)
	{
		std::cout << list.GetAt(i) << " ";
	}
	std::cout << std::endl;

	for (size_t i = 0; i < snd.Size(); i++)
	{
		std::cout << snd.GetAt(i) << " ";
	}
	std::cout << std::endl;

    return 0;
}

