#include <iostream>
#include "HashTable_CA.h"

using namespace std;

BST::BST(int k, int v) : value(v), key(k)
{
	parent = nullptr;
	left = nullptr;
	right = nullptr;
	root = nullptr;
	bf = 0;
	hl = 0;
	hp = 0;
	is_empty = false;
}

HashTable_CA::HashTable_CA() : size(0), capacity(1)
{
	tab = new BST[capacity];
}

HashTable_CA::~HashTable_CA()
{
	delete[] tab;
}

void HashTable_CA::increase_capacity()
{
	//zwiekszenie dwu krotnie pojemnosci
	int new_capacity = capacity * 2;

	//stworzenie nowej tablicy o nowe pojemnosci
	BST* new_tab = new BST[new_capacity];

	for (int i = 0; i < capacity; ++i)
	{
		//jezeli element tablicy nie jest pusty
		if (!tab[i].is_empty)
		{
			//wytypowanie nowego indkesu dla klucza przy nowej pojemnosci
			int j = tab[i].key % new_capacity;

			//dopoki wystepuje kolizja
			//WROCIC!!!!!!!!!!!!!!!!!!

			//przepisanie elementow do nowej tablicy
			new_tab[j] = tab[i];
		}
	}

	delete[] tab;
	//zaktualizowanie zmiennych 
	tab = new_tab;
	capacity = new_capacity;
}

void HashTable_CA::insert(int v, int k)
{
	if (size >= capacity / 2)
	{
		increase_capacity();
	}

	//wytypowanie nowego indeksu za pomoca funkcji hashujacej
	int i = hash(k);

	//przypisanie pod wytypowany indkes tablicy nowego wezla drzewa znajdujacego sie pod tym indeksem
	tab[i].insert_BST(v,k);
	size++;
}

int HashTable_CA::hash(int k) const
{
	//dzieki funkcji modulo indeks bedzie zawsze mniejszy od pojemnosci
	return k % capacity;
}


void BST::insert_BST(int v, int k)
{
	//tworzymy nowy wezel drzewa
	BST new_node(v, k);

	//jezeli drzewo jest puste, to nowy wezel staje sie rootem
	if (root == nullptr)
	{
		root->value = new_node.value;
		root->key = new_node.key;
	}
	else
	{
		//jezeli klucz wezla jest mniejszy od klucza roota idziemy do lewego poddrzewa od roota
		if (new_node.key < root->key)
		{
			//je¿eli lewe dziecko roota jest puste, przypisujemy mu wartosci i wychodzimy z funkcji
			if (root->left == nullptr)
			{
				root->left->key = new_node.key;
				root->left->value = new_node.value;
				new_node.parent = root->left;
				return;
			}

			//jezeli nie, to tworzymy wskaŸnik iterujacy po elementach drzewa
			else
			{
				BST* current = new BST;
				current = root;
				current->key = root->left->key;
				current->value = root->left->value;

				//dopoki wskzanik na cos wskazuje
				while (current)
				{
					//jezeli lewe dziecko wzkaznika nie jest puste i klucz nowego wêzla jest mniejszy od klucza wkzanika idziemy w lewo
					if ((current->left != nullptr) && (new_node.key < current->key))
					{
						current = current->left;
						current->key = current->left->key;
						current->value = current->left->value;
					}
					//jezeli lewe dziecko wzkaznika jest puste i klucz nowego wezla jest mnjeszy od klucza wzkaznika przypisujemy mu wartosci i wychodzimy z funkcji
					if ((current->left == nullptr) && (new_node.key < current->key))
					{
						current->left->key = new_node.key;
						current->left->value = new_node.value;
						new_node.parent = current;
						new_node.left = nullptr;
						new_node.right = nullptr;
						return;
					}


					//jezeli prawe dziecko wzkaznika nie jest puste i klucz nowego wêzla jest >= od klucza wkzanika idziemy w prawo
					if ((current->right != nullptr) && (new_node.key >= current->key))
					{
						current = current->right;
						current->key = current->right->key;
						current->value = current->right->value;
					}
					//jezeli prawe dziecko wzkaznika jest puste i klucz nowego wezla jest >= od klucza wzkaznika przypisujemy mu wartosci i wychodzimy z funkcji
					if ((current->right == nullptr) && (new_node.key >= current->key))
					{
						current->right->key = new_node.key;
						current->right->value = new_node.value;
						new_node.parent = current;
						new_node.left = nullptr;
						new_node.right = nullptr;
						return;
					}
					
					delete current;
				}
				
			}
			
		}

		//jezeli klucz wezla jest wiekszy/rowny od klucza roota idziemy do prawego poddrzewa od roota
		else if (new_node.key >= root->key)
		{
			//je¿eli prawe dziecko roota jest puste, przypisujemy mu wartosci i wychodzimy z funkcji
			if (root->right == nullptr)
			{
				root->right->key = new_node.key;
				root->right->value = new_node.value;
				new_node.parent = root->right;
				return;
			}


			//jezeli nie, to tworzymy wskaŸnik iterujacy po elementach drzewa
			else
			{
				BST* current = new BST;
				current = root;
				current->key = root->left->key;
				current->value = root->left->value;




			}

		}
	}
}



