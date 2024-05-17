#pragma once
#include <iostream>

using namespace std;

class Node
{
	int value;
	int key;

public:
	Node(int v, int k);
	Node();
	friend class HashTable_OA;
};

class HashTable_OA
{
	Node* tab;
	int size;
	int capacity;

public:
	HashTable_OA();
	~HashTable_OA();

	void insert(int v, int k);
	int hash(int k);
	void remove();
	void increase_capacity();

};
