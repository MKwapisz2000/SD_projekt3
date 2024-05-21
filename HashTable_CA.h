#pragma once
#include <iostream>


using namespace std;


class BST
{
	BST* parent;
	BST* left;
	BST* right;
	BST* root;
	int bf;
	int hl;
	int hp;
	int key;
	int value;
	bool is_empty;

public:
	BST(int v, int k);
	BST(): value(0), key(0), is_empty(true) {}

	void insert_BST(int v, int k);

	friend class HashTable_CA;


};

class HashTable_CA {
	BST* tab;
	int size;
	int capacity;

	int hash(int k) const;

public:
	HashTable_CA();
	~HashTable_CA();
	int hash(int k) const;
	void insert(int v, int k);
	void increase_capacity();
	
};