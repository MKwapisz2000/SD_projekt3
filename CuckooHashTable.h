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
