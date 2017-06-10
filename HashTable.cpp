#pragma once

#include "stdafx.h"
#include "HashTableh.h"
#include "DoublyLinkedList.h"
#include <random>
#include <array>
#include <chrono>
#include <iostream>

using namespace std;

HashTable::HashTable(void)
{
	BuildHashTable();
}

HashTable::~HashTable(void)
{

}

void HashTable::BuildHashTable()
{
	// create hash index size 10 filled with pointers to linked lists
	hashListPtr = new vector<DoublyLinkedList*>(10);
	// does anyone have a better way of doing this?
	hashList = *hashListPtr;

	for (int i = 0; i < 10; i++)
	{
		hashList[i] = new DoublyLinkedList;
		hashList[i]->InitializeList();
	}
	// call key generator 30 times and populate the hashList
	for (int i = 0; i < 30; i++)
	{
		// right now we are just inserting keys without values, so set
		// default value to 1
		TableInsert(hashList, 1, KeyGenerator());
	}

}

void HashTable::TableInsert(vector<DoublyLinkedList*> table, int value, int key)
{
	int hashIndex = Hash(key);
	if (table[hashIndex]->GetFirst() == nullptr )
	{
		table[hashIndex]->InsertFirst(value, key);
	}
	else
	{
		table[hashIndex]->InsertLast(value, key);
	}
}

// returns random key value between 1 and 50
int HashTable::KeyGenerator()
{
	int key;
	// seed that runs off of time... never did like this method
	int timeSeed = chrono::system_clock::now().time_since_epoch().count();
	// n = 50, the range of keys is from 0 to 50

	default_random_engine generator(timeSeed);
	uniform_int_distribution<int> distribution(0, n);
	key = distribution(generator);

	return key;
}
// +
// returns table index where the key should be inserted
int HashTable::Hash(int xKey)
{
	// M is 10
	return xKey % M;
}

void HashTable::PrintHashTable()
{
	for (int i = 0; i < M; i++)
	{
		hashList[i]->Display();
		cout << endl;
	}
}
