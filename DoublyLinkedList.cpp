

#include "stdafx.h"
#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

// Constructor
Node::Node(void)
{
	data = 0;
	previous = nullptr;
	next = nullptr;
}

// Constructor
/*
Node::Node(int inElement, Node* nodePtr)
{
data = inElement;
//
previous = previous->next;
next = nodePtr;
}
*/
Node::Node(int inValue)
{
	data = inValue;
	previous = nullptr;
	next = nullptr;
}

// Destructor
Node::~Node(void)
{

}

DoublyLinkedList::DoublyLinkedList(void)
{

}

DoublyLinkedList::~DoublyLinkedList(void)
{

}

void DoublyLinkedList::DestroyList()
{
	Node* temp;

	while (firstNode != nullptr)
	{
		temp = firstNode;
		firstNode = firstNode->next;
		temp = nullptr;
		delete temp;
	}

	lastNode = nullptr;
} // end DestroyList()

Node* DoublyLinkedList::GetFirst()
{
	return firstNode;
} // end GetFirst()

Node* DoublyLinkedList::GetLast()
{
	return lastNode;
} // end GetLast()

void DoublyLinkedList::InitializeList()
{
	DestroyList();
} // end InitializeList

void DoublyLinkedList::InsertFirst(int inValue)
{
	Node* newNode = new Node(inValue);

	if (firstNode != nullptr)
	{
		firstNode->previous = newNode;
		newNode->next = firstNode;
		firstNode = newNode;
	}

	if (firstNode == nullptr)
	{
		firstNode = newNode;
	}

	if (lastNode == nullptr)
	{
		lastNode = firstNode;
	}

	listLength++;
} // end InsertFirst()

void DoublyLinkedList::InsertLast(int inValue)
{
	Node* newNode = new Node(inValue);

	if (lastNode == nullptr)
	{
		lastNode = newNode;
	}
	else
	{
		lastNode->next = newNode;
		newNode->previous = lastNode;
		lastNode = newNode;
	}

	listLength++;
}

bool DoublyLinkedList::IsEmpty()
{
	// super naive, consider improving this later
	if (firstNode != nullptr)
		return false;
	else
		return true;
}

void DoublyLinkedList::DeleteFirst()
{
	Node* temp = firstNode;

	if (firstNode->next == nullptr)
	{
		// I read online (stackoverflow) that you're supposed to delete then
		// set pointer to null, but when debugging nulling first seems
		// to be much cleaner the node's previous will point to nullptr
		// instead of a large negative value.
		firstNode = nullptr;
		lastNode = nullptr;
		delete firstNode;
		delete lastNode;
	}
	else
	{
		firstNode->next->previous = temp;
		firstNode = firstNode->next;
		firstNode->previous = nullptr;
		temp = nullptr;
		delete temp;
	}

	listLength--;
} // end DeleteFirst()

void DoublyLinkedList::DeleteLast()
{
	Node* temp = lastNode;

	if (lastNode->previous == nullptr)
	{
		firstNode = nullptr;
		lastNode = nullptr;
		delete firstNode;
		delete lastNode;
	}
	else
	{
		lastNode->previous->next = temp;
		lastNode = lastNode->previous;
		lastNode->next = nullptr;
		temp = nullptr;
		delete temp;
	}

	listLength--;
} // end DeleteLast()

void DoublyLinkedList::DeleteNode(int inValue)
{
	Node* temp = Find(inValue);

	if (temp == firstNode)
	{
		temp = firstNode->next;
		firstNode = temp;
		temp = nullptr;
		firstNode->previous = nullptr;
		delete temp;
	}
	else if (temp == lastNode)
	{
		temp = lastNode->previous;
		lastNode = temp;
		temp = nullptr;
		lastNode->next = nullptr;
		delete temp;
	}
	else
	{
		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;
		temp = nullptr;
		delete temp;
	}
} // end DeleteNode()

Node* DoublyLinkedList::Find(int searchValue)
{
	Node* current = firstNode;
	while (current != nullptr)
	{
		if (current->data == searchValue)
		{
			cout << "Found node with value " << searchValue << endl;
			return current;
		}
		current = current->next;
	}
	cout << "Value not found." << endl;
	return 0;
} // end Find()

void DoublyLinkedList::InsertNodeAfter(int node, int inValue)
{
	Node* temp = Find(node);
	Node* newNode = new Node(inValue);

	if (temp == lastNode)
	{
		InsertLast(inValue);
	}
	else
	{
		newNode->next = temp->next;
		temp->next->previous = newNode;
		newNode->previous = temp;
		temp->next = newNode;
	}
	listLength++;
} // end InsertNodeAfter()

void DoublyLinkedList::InsertNodeBefore(int node, int inValue)
{
	Node* temp = Find(node);
	Node* newNode = new Node(inValue);

	if (temp == firstNode)
	{
		InsertFirst(inValue);
	}
	else
	{
		newNode->previous = temp->previous;
		temp->previous->next = newNode;
		newNode->next = temp;
		temp->previous = newNode;
	}
	listLength++;
} // end InsertNodeBefore()

int DoublyLinkedList::NodeCount()
{
	cout << "Node count: " << listLength << endl;
	// naive
	return listLength;
	// int nodeCount = 0;
	/*
	Node* temp = firstNode;
	while (temp != nullptr)
	{
	temp = temp->next;
	nodeCount++;
	}
	return nodeCount;
	*/
} // end NodeCount()

void DoublyLinkedList::Display()
{
	// TODO: wrap this in b_IsEmpty()
	if (firstNode == nullptr)
	{
		cout << "the list is empty.";
		return;
	}

	Node* current = firstNode;
	// Because how could our pointer ever point to something that
	// doesn't exist eh?
	while (current->next != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
}
