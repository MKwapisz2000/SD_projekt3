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

// Funkcja haszująca 1
int CuckooHashTable::hash1(int key) const 
{
    return key % capacity;
}

// Funkcja haszująca 2
int CuckooHashTable::hash2(int key) const 
{
    return (key / capacity) % capacity;
}

// Funkcja rehashująca
void CuckooHashTable::rehash() 
{
    Node* old_table1 = table1;
    Node* old_table2 = table2;
    int old_capacity = capacity;

    capacity *= 2;  // Zwiększenie pojemności
    table1 = new Node[capacity];
    table2 = new Node[capacity];
    size = 0;

    for (int i = 0; i < old_capacity; ++i)  
    {
        if (!old_table1[i].is_empty) 
        {
            insert(old_table1[i].value, old_table1[i].key);
        }

        if (!old_table2[i].is_empty) 
        {
            insert(old_table2[i].value, old_table2[i].key);
        }
    }

    delete[] old_table1;
    delete[] old_table2;
}

// Funkcja zamieniająca elementy
void CuckooHashTable::swap(Node& a, Node& b) 
{
    Node temp = a;
    a = b;
    b = temp;
}

// Funkcja wstawiająca element do tablicy
void CuckooHashTable::insert(int v, int k) 
{
    if (size >= capacity) 
    {
        rehash();
    }

    Node newNode(v, k);
    for (int count = 0; count < 2 * capacity; ++count) 
    {
        int pos1 = hash1(k);
        if (table1[pos1].is_empty) 
        {
            table1[pos1] = newNode;
            size++;
            return;
        }

        swap(newNode, table1[pos1]);

        int pos2 = hash2(newNode.key);
        if (table2[pos2].is_empty) 
        {
            table2[pos2] = newNode;
            size++;
            return;
        }

        swap(newNode, table2[pos2]);
    }

    rehash();
    insert(newNode.value, newNode.key);
}
