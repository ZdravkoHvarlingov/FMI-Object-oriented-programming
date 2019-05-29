#pragma once
#include <vector>
#include <algorithm>

template <typename T>
class Tree
{
public:
	Tree(int capacity = 32);
	int GetRows() const;
	const T& GetAt(int i, int j) const;

	Tree<T> operator+(Tree &other);
	void operator++();

private:
	//vector of tree rows
	std::vector<std::vector<T>> tree;
	int capacity;
};

template<typename T>
inline Tree<T>::Tree(int capacity)
	: capacity(capacity)
{}

template<typename T>
inline int Tree<T>::GetRows() const
{
	return tree.size();
}

template<typename T>
inline const T& Tree<T>::GetAt(int i, int j) const
{
	int row = i + j;
	return tree[row][i];
}

template<typename T>
inline Tree<T> Tree<T>::operator+(Tree & other)
{
	Tree<T> result(capacity + other.capacity);
	int numberOfRows = other.tree.size() < tree.size() ? other.tree.size() : tree.size();

	for (size_t i = 0; i < numberOfRows; i++)
	{
		result.tree.push_back(std::vector<T>());
		for (size_t j = 0; j < i + 1; j++)
		{
			result[i].push_back(tree[i][j] + other.tree[i][j]);
		}
	}

	return result;
}

template<typename T>
inline void Tree<T>::operator++()
{
	tree.push_back(std::vector<T>());
	int row = tree.size() - 1;
	if (tree.size() == 1)
	{
		tree[row].push_back(T());
	}
	else
	{
		tree[row].push_back(tree[row - 1][0]);
		for (int i = 0; i < row + 1 - 2; i++)
		{
			tree[row].push_back(tree[row - 1][i] + tree[row - 1][i + 1]);
		}
		tree[row].push_back(tree[row - 1][tree[row - 1].size() - 1]);
	}
}
