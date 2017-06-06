// DoublyLinkedList.h
// Brian Keppinger

#pragma once

using namespace std;

// class DoublyLinkedList;

struct Node
{
	friend class DoublyLinkedList;

public:
	// Constructors
	Node(void);
	Node(int);
	// Node(int, Node*);

	// Destructor
	~Node(void);

private:
	int data;
	Node* previous;
	Node* next;
};

class DoublyLinkedList
{
public:
	DoublyLinkedList(void);
	~DoublyLinkedList(void);

	void DoublyLinkedList::DestroyList();
	Node* GetFirst();
	Node* GetLast();
	void DoublyLinkedList::InitializeList();

	void DoublyLinkedList::InsertFirst(int);
	void DoublyLinkedList::InsertLast(int);
	bool DoublyLinkedList::IsEmpty();

	void DoublyLinkedList::DeleteFirst();
	void DoublyLinkedList::DeleteLast();
	void DoublyLinkedList::DeleteNode(int);

	void DoublyLinkedList::Display();
	Node* DoublyLinkedList::Find(int);

	void DoublyLinkedList::InsertNodeAfter(int node, int inValue);
	void DoublyLinkedList::InsertNodeBefore(int node, int inValue);
	int DoublyLinkedList::NodeCount();

private:
	// probably want a head pointer

	Node* firstNode;
	// Node* nextNode;
	Node* lastNode;
	int listLength;
};
