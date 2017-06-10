#pragma once


#include <vector>

using namespace std;


class HashTable 
{
	friend class DoublyLinkedList;
public:

	HashTable(void);
	~HashTable(void);

	void BuildHashTable();
	void TableInsert(vector<DoublyLinkedList*>, int, int);
	int Hash(int);
	void PrintHashTable();
	// returns one psudo randomly generated key
	int KeyGenerator();
	// void PrintTable();
	// table holds 10 slots
	int M = 10;

	// max value of keys
	// keys are integers from 1 to 50
	int n = 50;

private:
	// DoublyLinkedList* listPtr[10];
	vector<DoublyLinkedList*>* hashListPtr;
	vector<DoublyLinkedList*> hashList;

};