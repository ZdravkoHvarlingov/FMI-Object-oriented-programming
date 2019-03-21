#pragma once

struct Node
{
	int value;
	Node *next;

	Node(int value, Node *next = nullptr)
	{
		this->value = value;
		this->next = next;
	}
};

class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList &other);

	int Size() const;
	void PushFront(int element);
	
	//Node *end;
	void PushEnd(int element);
	void PushAt(int position, int element);
	int GetAt(int position) const;

	//TO DO
	/*void RemoveFront();
	void RemoveEnd();
	void RemoveAt();
	int GetFront() const;
	int GetEnd() const;*/

	LinkedList& operator=(const LinkedList &other);

	~LinkedList();

private:

	void CopyHelper(const LinkedList &other);
	void EraseMemory(Node *node);

	Node *head;
	int size;
};
