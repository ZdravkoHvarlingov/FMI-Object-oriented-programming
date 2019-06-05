#include "Stack.h"
#include <iostream>

int main()
{
	dataStructures::Stack st;
	for (size_t i = 0; i < 10; i++)
	{
		st.push(i);
	}
	/*std::cin >> st;
	std::cout << st << std::endl;*/

	while (!st.empty())
	{
		std::cout << st.top() << " ";

		st.pop();
	}
	std::cout << std::endl;

    return 0;
}

