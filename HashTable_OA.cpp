#include <iostream>
#include "HashTable_OA.h"

using namespace std;

HashTable_OA::HashTable_OA() : size(0), capacity(1) 
{
	tab = new Node[capacity];
}

HashTable_OA::~HashTable_OA() 
{
	delete[] tab;
}

void HashTable_OA::increase_capacity() 
{
	//zwiekszenie dwu krotnie pojemnosci
	int new_capacity = capacity * 2;

	//stworzenie nowej tablicy o nowe pojemnosci
	Node* new_tab = new Node[new_capacity];

	for (int i = 0; i < capacity; ++i) 
	{
		//jezeli element tablicy nie jest pusty
		if (!tab[i].is_empty)
		{
			//wytypowanie nowego indkesu dla klucza przy nowej pojemnosci
			int j = tab[i].key % new_capacity;

			//dopoki wystepuje kolizja
			while (!new_tab[j].is_empty) 
			{
				//typowanie nowego indeksu
				j = (j + 1) % new_capacity;
			}

			//przepisanie elementow do nowej tablicy
			new_tab[j] = tab[i];
		}
	}

	delete[] tab;
	//zaktualizowanie zmiennych 
	tab = new_tab;
	capacity = new_capacity;
}

void HashTable_OA::insert(int v, int k)
{
	if (size >= capacity / 2)
	{
		increase_capacity();
	}

	//stworzenie nowego elementu tablicy
	Node new_node(v, k);

	//wytypowanie nowego indeksu za pomoca funkcji hashujacej
	int i = hash(k);

	//dopoki zachodzi kolizja
	while ((!tab[i].is_empty) && (tab[i].key != k))
	{
		//typoowanie nowego indeksu
		i = (i + 1) % capacity;
	}
	//przypisanie pod wytypowany indkes nowego elementu
	tab[i] = new_node;
	size++;
} 

int HashTable_OA::hash(int k) const 
{
	//dzieki funkcji modulo indeks bedzie zawsze mniejszy od pojemnosci
	return k % capacity;
}

void HashTable_OA::show() const
{
	//iterowanie po wszystkich (nie pustych) elementach i wypisanie danych
	for (int i = 0; i < capacity; i++) 
	{
		if (!tab[i].is_empty) 
		{
			cout <<"INDEKS ["<<i<<"]   KLUCZ [" << tab[i].key << "]   WARTOSC [" << tab[i].value <<"]"<< endl;
		}
	}
	if (size == 0)
	{
		cout << "Tablica jest pusta.";
	}
}
int  HashTable_OA::capacity_() const
{
	//zwrocenie pojemnosci
	return capacity;
}

int  HashTable_OA::size_() const
{
	//zwrocenie rozmiaru
	return size;
}

void HashTable_OA::remove(int k) 
{
	//szukamy indkesu elementu o wskazanym kluczu 
	int i = hash(k);
	while (!tab[i].is_empty) 
	{
		//jezeli podany klucz zgadza sie z zapisanym pod indeksem i
		if(tab[i].key == k)
		{
			//wywolanie konstruktora domyslnego do miejsca tablicy w ktorym znajduje sie element do usuniecia
			tab[i] = Node(); 
			size--;
			cout << "Usuniety element znajdowal sie pod indeksem " << i << endl;
			return;
		}
		i = (i + 1) % capacity;
	}
	cout << "Podany klucz nie istnieje w tablicy." << endl;
}

void HashTable_OA::clear()
{
	//wyczyszczenie tablicy
	size = 0;
	capacity = 1;
}