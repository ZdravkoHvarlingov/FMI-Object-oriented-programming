#include <assert.h>
#include <stack>
#include <iostream>

struct Node
{
	int value;
	Node *next;

	Node(int value, Node *next = nullptr)
		: value(value), next(next)
	{}
};

int GetTail(Node *head)
{
	while (head->next != nullptr)
	{
		head = head->next;
	}

	return head->value;
}

int GetHead(Node *head)
{
	return head->value;
}

//Modifies the current list
Node* AddFront(Node *head, int value)
{
	return new Node(value, head);
}

//Modifies the current list
Node* RemoveFront(Node *head)
{
	Node *newHead = head->next;
	delete head;

	return newHead;
}

//Modifies the current list
Node* AddTail(Node *head, int value)
{
	Node *crr = head;
	while (crr->next != nullptr)
	{
		crr = crr->next;
	}

	crr->next = new Node(value);
	return head;
}

//Modifies the current list
Node* RemoveTail(Node *head)
{
	if (head->next == nullptr)
	{
		delete head;
		return nullptr;
	}

	Node *crr = head;
	while (crr->next->next != nullptr)
	{
		crr = crr->next;
	}

	delete crr->next;
	crr->next = nullptr;
	return head;
}

//Modifies the current list
void DeleteAll(Node *head)
{
	if (head == nullptr)
	{
		return;
	}

	DeleteAll(head->next);
	delete head;
}

//Creates a new list
Node* MakeACopy(Node *head)
{
	if (head == nullptr)
	{
		return nullptr;
	}

	Node *newHead = new Node(head->value);
	Node *crrNew = newHead;
	while (head->next != nullptr)
	{
		crrNew->next = new Node(head->next->value);
		head = head->next;
		crrNew = crrNew->next;
	}

	return newHead;
}

Node* GetMiddleNode(Node *head)
{
	//Another approach is just to pass through the linked list once, get its size and then traverse to the middle element
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}
	
	//1 2 3 4 5
	//1 2 3 4
	Node *fastPtr = head;
	Node *slowPtr = head;
	while (fastPtr->next != nullptr && fastPtr->next->next != nullptr)
	{
		fastPtr = fastPtr->next->next;
		slowPtr = slowPtr->next;
	}

	return slowPtr;
}

//Creates a new list
Node* Reverse(Node *head)
{
	Node *crr = MakeACopy(head);
	Node *previous = nullptr;
	Node *next = nullptr;
	while (crr != nullptr)
	{
		next = crr->next;
		crr->next = previous;
		previous = crr;
		crr = next;
	}

	return previous;
}

Node* FindTheNthFromTheEndHelper(Node *head, int &positionFromEnd, int N)
{
	if (head == nullptr)
	{
		return nullptr;
	}

	Node *res = FindTheNthFromTheEndHelper(head->next, positionFromEnd, N);
	++positionFromEnd;
	if (positionFromEnd == N)
	{
		return head;
	}

	return res;
}

Node* FindTheNthFromTheEnd(Node *head, int N)
{
	int positionFromEnd = 0;
	return FindTheNthFromTheEndHelper(head, positionFromEnd, N);
}

//Creates a new list
Node* DeleteNNodesAfterMNodes(Node *head, int n, int m)
{
	Node *crr = head;
	for (size_t i = 0; i < m - 1; i++)
	{
		crr = crr->next;
	}

	for (size_t i = 0; i < n; i++)
	{
		Node *toDelete = crr->next;
		crr->next = crr->next->next;
		delete toDelete;
	}

	return head;
}

int GetMax(Node *head)
{
	Node *maxNode = nullptr;
	while (head != nullptr)
	{
		if (maxNode == nullptr || maxNode->value < head->value)
		{
			maxNode = head;
		}

		head = head->next;
	}

	return maxNode->value;
}

//modifies the linked list
Node *RemoveNode(Node *head, int value)
{
	if (head == nullptr)
	{
		return nullptr;
	}

	if (head->value == value)
	{
		return RemoveFront(head);
	}

	Node *headSave = head;
	while (head->next != nullptr && head->next->value != value)
	{
		head = head->next;
	}

	if (head->next == nullptr)
	{
		return headSave;
	}

	Node *nodeToDelete = head->next;
	head->next = head->next->next;
	delete nodeToDelete;

	return headSave;
}

//Creates a new list
Node* SortLinkedList(Node *head)
{
	int size = 0;
	Node *crr = head;
	while (crr != nullptr)
	{
		++size;
		crr = crr->next;
	}

	Node *listCopy = MakeACopy(head);
	Node *res = nullptr;
	for (size_t i = 0; i < size; i++)
	{
		int max = GetMax(listCopy);
		listCopy = RemoveNode(listCopy, max);
		res = AddFront(res, max);
	}

	return res;
}

bool CheckIfPalindrome(Node *head)
{
	std::stack<Node*> reversedList;
	Node *crr = head;
	while (crr != nullptr)
	{
		reversedList.push(crr);
		crr = crr->next;
	}

	crr = head;
	while (crr != nullptr)
	{
		Node *reversedCrr = reversedList.top(); reversedList.pop();
		if (crr->value != reversedCrr->value)
		{
			return false;
		}
		crr = crr->next;
	}

	return true;
}

int main()
{
	Node *head = new Node(5, new Node(4, new Node(3, new Node(2, new Node(1)))));
	Node *sorted = SortLinkedList(head);

	while (sorted != nullptr)
	{
		std::cout << sorted->value << std::endl;

		sorted = sorted->next;
	}
	std::cout << "Is palindrome: " << CheckIfPalindrome(head) << std::endl;

	DeleteAll(head);
	DeleteAll(sorted);

	Node *palindrome = new Node(5, new Node(4, new Node(3, new Node(4, new Node(5)))));
	Node *sortedPalindrome = SortLinkedList(palindrome);
	while (sortedPalindrome != nullptr)
	{
		std::cout << sortedPalindrome->value << std::endl;

		sortedPalindrome = sortedPalindrome->next;
	}
	std::cout << "Is palindrome: " << CheckIfPalindrome(palindrome) << std::endl;

    return 0;
}

