#include "Stack.h"

using namespace dataStructures;

int Stack::top() const
{
	return elements[elements.size() - 1];
}

void Stack::pop()
{
	elements.pop_back();
}

void Stack::push(int num)
{
	elements.push_back(num);
}

bool Stack::empty() const
{
	return elements.size() == 0;
}

int Stack::size() const
{
	return elements.size();
}

//Serialization
std::ostream & dataStructures::operator<<(std::ostream & out, Stack & st)
{
	out << st.elements.size() << " ";
	for (int element : st.elements)
	{
		out << element << " ";
	}

	return out;
}

//Deserialize
std::istream & dataStructures::operator>>(std::istream & in, Stack & st)
{
	int numberOfElements;
	in >> numberOfElements;

	for (int i = 0; i < numberOfElements; i++)
	{
		int crrElement;
		in >> crrElement;
		st.elements.push_back(crrElement);
	}

	return in;
}

