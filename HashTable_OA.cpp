#include <iostream>
#include "HashTable_OA.h"

using namespace std;

Node::Node(int v, int k) : value(v), key(k)
{}

Node::Node(): value(0), key(0)
{}

HashTable_OA::HashTable_OA()
{
	tab = nullptr;
	size = 0;
	capacity = 0;
}

HashTable_OA::~HashTable_OA()
{}

void HashTable_OA::increase_capacity()
{
	int new_capacity;

	if (capacity == 0)
	{
		new_capacity = 1;
	}
	else
	{
		new_capacity = capacity * 2;
	}

	Node* new_tab = new Node[new_capacity];
	for (int i = 0; i < size; i++)
	{
		new_tab[i] = tab[i];
	}
	delete[] tab;
	tab = new_tab;

	capacity = new_capacity;
}

void HashTable_OA::insert(int v, int k)
{
	//Zwieksz pojemnosc tablicy, jezeli rozmiar jest od niej wiekszy rowny
	if (size >= capacity)
	{
		increase_capacity();
	}

	//Nowy element tablicy
	Node* new_node = new Node(v, k);

	//Wytypowanie indeksu dla elementu za pomoca funkcji haszujacej
	int index = hash(k);

	//Wykrywanie kolizji (pod wytypownym indeksem znajduje sie juz inny klucz)
	//Szukamy pierwszego wolnego indeksu
	while ((tab[index].key != k) && (tab[index].key != 0))
	{
		index++;
		if (index >= (capacity - 1))
		{
			index = 0;
		}
	}

	tab[index].key = k;
	tab[index].value = v;

	size++;
}

int HashTable_OA::hash(int k)
{
	//Dzieki modulo, wytypowany indeks bedzie zawsze mnijeszy od rozmiaru 
	return k % capacity;
}