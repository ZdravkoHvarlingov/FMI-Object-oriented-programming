#include "Stack.h"
#include <iostream>

int main()
{
	Stack st;
	for (int i = 0; i < 5; i++)
	{
		st.Push(i);
	}

	Stack st2 = st;

	while (!st.IsEmpty())
	{
		int top = st.Top();
		st.Pop();
		std::cout << "Element: " << top << ", new size: "<< st.Size() << std::endl;
	}

    return 0;
}

