#pragma once
#include <iostream>

class Node 
{
    int value;
    int key;
    bool is_empty;

public:
    Node(int v, int k) : value(v), key(k), is_empty(false) {}
    Node() : value(0), key(0), is_empty(true) {}

    friend class CuckooHashTable;
};

class CuckooHashTable 
{
    Node* table1;
    Node* table2;
    int capacity;
    int size;
    int rehash_count;

    int hash1(int key) const;
    int hash2(int key) const;
    void rehash();
    void swap(Node& a, Node& b);

public:
    CuckooHashTable();
    ~CuckooHashTable();
    void insert(int v, int k);
    void show() const;
    void remove(int k);
};
