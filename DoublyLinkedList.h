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
	// Node(int);
	Node(int, int);
	// Node(int, Node*);

	// Destructor
	~Node(void);

private:
	int data;
	int key;
	Node* previous;
	Node* next;
};

class DoublyLinkedList
{
	friend struct Node;
public:
	DoublyLinkedList(void);
	~DoublyLinkedList(void);

	void DoublyLinkedList::DestroyList();
	Node* GetFirst();
	Node* GetLast();
	void DoublyLinkedList::InitializeList();

	void DoublyLinkedList::InsertFirst(int, int);
	void DoublyLinkedList::InsertLast(int, int);
	bool DoublyLinkedList::IsEmpty();

	void DoublyLinkedList::DeleteFirst();
	void DoublyLinkedList::DeleteLast();
	void DoublyLinkedList::DeleteNode(int, int);

	void DoublyLinkedList::Display();
	Node* DoublyLinkedList::Find(int);

	void DoublyLinkedList::InsertNodeAfter(int node, int inData, int inKey);
	void DoublyLinkedList::InsertNodeBefore(int node, int InData, int inKey);
	int DoublyLinkedList::NodeCount();

private:
	// probably want a head pointer

	Node* firstNode;
	// Node* nextNode;
	Node* lastNode;
	int listLength;
};
