#pragma once
#include <iostream>


using namespace std;


class BST;

class Node_BST
{

	Node_BST* parent;
	Node_BST* left;
	Node_BST* right;
	
	int bf;
	int hl;
	int hp;
	int key;
	int value;
	

public:
	Node_BST(int v, int k);
	Node_BST() : value(0), key(0), bf(0), hl(0), hp(0), parent(nullptr), left(nullptr), right(nullptr) {}

	friend class BST;

};

class BST
{
	Node_BST* root;
	bool is_empty;
	int size_BST;
	
	int get_key() const;
	int get_value() const;
	void insert(Node_BST *& node , int v, int k);

public:
	BST() : root(nullptr), is_empty(true), size_BST(0) {}
	void insert_BST(int v, int k);
	void remove_BST(int k);
	void rotation(Node_BST *node, string bf);
	void update_bf(Node_BST *node);
	int getHeight(Node_BST* node);
	void show_BST(Node_BST* node) const;
	
	friend class HashTable_CA;
	
};

class HashTable_CA {
	BST* tab;
	int size;
	int capacity;

	

public:
	HashTable_CA();
	~HashTable_CA();
	int hash(int k) const;
	void insert(int v, int k);
	void remove(int k);
	void increase_capacity();
	void show() const;
	void clear();
	int capacity_() const;
	int size_() const;
};