#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = nullptr;
	size = 0;
}

LinkedList::LinkedList(const LinkedList & other)
	: LinkedList()
{
	CopyHelper(other);
}

int LinkedList::Size() const
{
	return size;
}

void LinkedList::PushFront(int element)
{
	Node *newNode = new Node(element);
	newNode->next = head;
	head = newNode;
	
	++size;
}

void LinkedList::PushEnd(int element)
{
	if (head == nullptr)
	{
		head = new Node(element);
	}
	else
	{
		Node *crr = head;
		while (crr->next != nullptr)
		{
			crr = crr->next;
		}
		crr->next = new Node(element);
	}

	++size;
}

void LinkedList::PushAt(int position, int element)
{
	Node *crr = head;
	--position;
	while (position > 0)
	{
		crr = crr->next;
	}

	crr->next = new Node(element, crr->next);
}

int LinkedList::GetAt(int position) const
{
	Node *crr = head;
	while (position > 0)
	{
		crr = crr->next;

		--position;
	}

	return crr->value;
}

LinkedList & LinkedList::operator=(const LinkedList & other)
{
	if (this != &other)
	{
		EraseMemory(head);
		head = nullptr;
		CopyHelper(other);
	}

	return *this;
}

LinkedList::~LinkedList()
{
	EraseMemory(head);
}

void LinkedList::CopyHelper(const LinkedList & other)
{
	Node *crr = other.head;
	while (crr != nullptr)
	{
		PushEnd(crr->value);

		crr = crr->next;
	}
}

void LinkedList::EraseMemory(Node * node)
{
	if (node == nullptr)
	{
		return;
	}

	EraseMemory(node->next);
	delete node;
}
