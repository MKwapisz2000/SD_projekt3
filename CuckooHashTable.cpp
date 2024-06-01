#include <iostream>
#include "CuckooHashTable.h"

// Konstruktor klasy CuckooHashTable
CuckooHashTable::CuckooHashTable() : capacity(1), size(0), rehash_count(0) 
{
    table1 = new Node[capacity];
    table2 = new Node[capacity];
}

// Destruktor klasy CuckooHashTable
CuckooHashTable::~CuckooHashTable() 
{
    delete[] table1;
    delete[] table2;
}
