// HashTableProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DoublyLinkedList.h"
#include "HashTableh.h"
/*
Implement a hash table making use of separate chaining.  
Thus, your Hash Project will require the use of your DoublyLinkedList class. i
The instance of the Hash class will need to make use of an array that can hold pointers to linked lists in order to implement separate chaining.
Assume that the keys are integers from 0 to n, where n = 50.  Assume that the array can hold M keys total, where M = 10.  
Allow a random key generator to fill the hash with 30 unique keys.  Add functionality that will output the contents of the hash table, 
with the data from a single singly linked list per line of output.  Use the hashing function h(x) = x MOD M to obtain array indices.
*/

int main()
{
	HashTable hashTable;
	hashTable.PrintHashTable();

    return 0;
}

