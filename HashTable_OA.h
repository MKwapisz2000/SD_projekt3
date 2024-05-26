#pragma once
#include <iostream>


using namespace std;

class Node {
	int value;
	int key;
	bool is_empty;

public:
	Node(int v, int k) : value(v), key(k), is_empty(false) {}
	Node() : value(0), key(0), is_empty(true) {}

	friend class HashTable_OA;
};

class HashTable_OA {
	Node* tab;
	int size;
	int capacity;

	//int hash(int k) const;

public:
	HashTable_OA();
	~HashTable_OA();
	int hash(int k) const;
	void insert(int v, int k);
	void increase_capacity();
	void show() const;
	int capacity_() const;
	int size_() const;
	void remove(int k);
	void clear();
};








