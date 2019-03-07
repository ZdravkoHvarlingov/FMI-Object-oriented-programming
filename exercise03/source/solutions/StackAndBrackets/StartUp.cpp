#include "Stack.h"
#include <iostream>

bool AreBracketsBalanced(const char *txt)
{
	Stack<char> st;
	for (size_t i = 0; i < strlen(txt); i++)
	{
		if (txt[i] == '(')
		{
			st.Push(txt[i]);
		}
		else if (txt[i] == ')' && st.Size() == 0)
		{
			return false;
		}
		else if (txt[i] == ')')
		{
			st.Pop();
		}
	}

	return st.Empty();
}

int main()
{
	Stack<int> st;
	st.Push(10);
	st.Push(11);
	st.Push(12);
	st.Push(13);
	st.Push(14);
	st.Push(15);

	while (!st.Empty())
	{
		std::cout << st.Pop() << " ";
	}
	std::cout << std::endl;

	std::cout << AreBracketsBalanced("(())") << std::endl;
	std::cout << AreBracketsBalanced("(()()())") << std::endl;
	std::cout << AreBracketsBalanced(")()") << std::endl;
	std::cout << AreBracketsBalanced(")()(") << std::endl;
	std::cout << AreBracketsBalanced("((())") << std::endl;

    return 0;
}

