#pragma once
#include <vector>
#include <iostream>

namespace dataStructures
{
	class Stack
	{
	public:
		int top() const;
		void pop();
		void push(int num);

		bool empty() const;
		int size() const;

		friend std::ostream& operator<<(std::ostream &out, Stack &st);
		friend std::istream& operator>>(std::istream &in, Stack &st);

	private:
		std::vector<int> elements;
	};
}


