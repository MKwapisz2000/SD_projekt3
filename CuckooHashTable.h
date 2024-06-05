#pragma once
#include <iostream>

class Nod
{
    int value;
    int key;
    bool is_empty;

public:
    Nod(int v, int k) : value(v), key(k), is_empty(false) {}
    Nod() : value(0), key(0), is_empty(true) {}

    friend class CuckooHashTable;
};

class CuckooHashTable 
{
    Nod* table1;
    Nod* table2;
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
    int capacity_() const;
    int size_() const;
    void clear();
};
