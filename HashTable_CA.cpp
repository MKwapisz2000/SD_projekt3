#include <iostream>
#include "HashTable_CA.h"

using namespace std;

Node_BST::Node_BST(int v, int k) : value(v), key(k)
{
	parent = nullptr;
	left = nullptr;
	right = nullptr;
	bf = 0;
	hl = 0;
	hp = 0;
	
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
			int j = tab[i].get_key() % new_capacity;

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

	//Dodajemy nowe drzewo tylko jeœli tablica jest pusta pod danym indeksem
	if (tab[i].is_empty)
	{
		tab[i].insert_BST(v, k);
		//Inkrementujemy liczbê drzew tylko wtedy, gdy dodajemy nowe drzewo
		size++; 
	}
	else 
	{
		//Dodajemy element do istniej¹cego drzewa
		tab[i].insert_BST(v, k); 
	}

}

int HashTable_CA::hash(int k) const
{
	//dzieki funkcji modulo indeks bedzie zawsze mniejszy od pojemnosci
	return k % capacity;
}


int BST::get_key() const
{
	return root->key;
}

int BST::get_value() const
{
	return root->value;
}


void BST::insert_BST(int v, int k)
{
	insert(root, v, k);
}

void BST::insert(Node_BST*& new_node, int v, int k)
{
	//tworzymy wskaznik iterujacy po elementach drzewa
	Node_BST* current = root;
	while (current)
	{
		//jezeli taki klucz juz istnieje w drzewie to nadpisujemy jego wartosc i wychodzimy z funkcji
		if (current->key == k)
		{
			current->value = v;
			return;
		}

		else if (k < current->key)
		{
			current = current->left;
		}

		else if (k >= current->key)
		{
			current = current->right;
		}
	}

	if (new_node == nullptr)
	{
		new_node = new Node_BST(v, k);
		is_empty = false;
		size_BST++;
		

		//jezeli nowy wezel nie ma rodzica to jest on korzeniem drzewa
		if (new_node->parent == nullptr)
		{
			root = new_node;
		}
		update_bf(new_node);

	}

	else if (k < new_node->key)
	{
		if (new_node->left == nullptr)
		{
			new_node->left = new Node_BST(v, k);
			new_node->left->parent = new_node; // Ustawienie rodzica przed wywo³aniem rekurencyjnym
			is_empty = false;
			size_BST++;
			update_bf(new_node);
		}
		else
		{
			insert(new_node->left, v, k);
		}
	}
	else if (k >= new_node->key)
	{
		if (new_node->right == nullptr)
		{
			new_node->right = new Node_BST(v, k);
			new_node->right->parent = new_node; // Ustawienie rodzica przed wywo³aniem rekurencyjnym
			is_empty = false;
			size_BST++;
			update_bf(new_node);
		}
		else
		{
			insert(new_node->right, v, k);
		}
	}
	update_bf(new_node);
	
}

int BST::getHeight(Node_BST* node) 
{
	if (node == nullptr) 
	{
		//zwracamy -1, poniewa¿ wysokoœæ pustego drzewa jest -1
		return -1; 
	}
	//zwracamy wieksza z wartosci +1 (by uwzglednic nowa grawedz)
	return 1 + max(getHeight(node->left), getHeight(node->right));
}

void BST::update_bf(Node_BST* node) 
{
	while (node != nullptr)
	{
		int hl = getHeight(node->left);
		int hp = getHeight(node->right);

		node->hl = hl;
		node->hp = hp;

		node->bf = hl - hp;

		std::cout << "Node Key: " << node->key << ", HL: " << hl << ", HP: " << hp << ", BF: " << node->bf << std::endl;

		if (node->bf == 2 || node->bf == -2) 
		{
			if ((node->bf == 2) && (node->left != nullptr) && (node->left->bf == -1))
			{
				// Rotacja LR
				rotation(node, "LR"); 
			}
			else if ((node->bf == -2) && (node->right != nullptr) && (node->right->bf == 1)) 
			{
				// Rotacja RL
				rotation(node, "RL");
			}
				

			else
			{
				if (node->bf == 2) 
				{
					// Rotacja LL
					rotation(node, "LL"); 
				}
				else if (node->bf == -2) 
				{
					// Rotacja RR
					rotation(node, "RR"); 

				}
			}
		}

		node = node->parent;
	}
}





void BST::rotation(Node_BST* node, string bf)	
{
	Node_BST* temp1;
	Node_BST* temp2;
	Node_BST* temp_parent;

	if (bf == "LL")
	{
		//typ ukladu LL
		if ((node->left != nullptr) && (node->left->left != nullptr))
		{
			temp1 = node;
			temp2 = node->left->right;
			temp_parent = node->parent;

			node->left->right = temp1;
			node->left->parent = temp_parent;

			//jezeli rodzic nie jest nullptr (node nie jest korzeniem)
			if (temp_parent != nullptr)
			{
				if (temp_parent->left == temp1)
				{
					temp_parent->left = node->left;
				}
				else
				{
					temp_parent->right = node->left;
				}
			}

			//jezeli node jest korzeniem
			else
			{
				root = node->left;
			}

			temp1->left = temp2;
			if (temp2 != nullptr)
			{
				temp2->parent = temp1;
			}

			temp1->parent = node->left;

			update_bf(node);
		}
	}


	if (bf == "LR")
	//typ ukladu LR
	{
		if ((node->left != nullptr) && (node->left->right != nullptr))
		{
			temp1 = node;
			temp2 = node->left->right;
			temp_parent = node->parent;
			

			//sprowadzenie do ukladu LL
			node->left->left = temp2;
			node->left->right = nullptr;
			

			
			//rozwiazanie ukladu LL
			temp1 = node;
			temp2 = node->left->right;
			temp_parent = node->parent;

			node->left->right = temp1;
			node->left->parent = temp_parent;

			//jezeli rodzic nie jest nullptr (node nie jest korzeniem)
			if (temp_parent != nullptr)
			{
				if (temp_parent->left == temp1)
				{
					temp_parent->left = node->left;
				}
				else
				{
					temp_parent->right = node->left;
				}
			}

			//jezeli node jest korzeniem
			else
			{
				root = node->left;
			}

			temp1->left = temp2;
			if (temp2 != nullptr)
			{
				temp2->parent = temp1;
			}

			temp1->parent = node->left;
			
			update_bf(node);
		}
	}
		

	if (bf == "RR")
	{
		//typ ukladu RR
		if ((node->right != nullptr) && (node->right->right != nullptr))
		{
			temp1 = node;
			temp2 = node->right->left;
			temp_parent = node->parent;

			node->right->left = temp1;
			node->right->parent = temp_parent;

			//jezeli rodzic nie jest nullptr (node nie jest korzeniem)
			if (temp_parent != nullptr)
			{
				if (temp_parent->right == temp1)
				{
					temp_parent->right = node->right;
				}
				else
				{
					temp_parent->left = node->right;
				}
			}

			//jezeli node jest korzeniem
			else
			{
				root = node->right;
			}

			temp1->right = temp2;
			if (temp2 != nullptr)
			{
				temp2->parent = temp1;
			}

			temp1->parent = node->right;

			update_bf(node);
		}
	}


	if (bf == "RL")
		//typ ukladu RL
	{
		if ((node->right != nullptr) && (node->right->left != nullptr))
		{
			temp1 = node;
			temp2 = node->right->left;
			temp_parent = node->parent;
			

			//sprowadzenie do ukladu RR
			node->right->right = temp2;
			node->right->left = nullptr;
			
			
			//rozwiazanie ukladu RR
			temp1 = node;
			temp2 = node->right->left;
			temp_parent = node->parent;

			node->right->left = temp1;
			node->right->parent = temp_parent;

			//jezeli rodzic nie jest nullptr (node nie jest korzeniem)
			if (temp_parent != nullptr)
			{
				if (temp_parent->right == temp1)
				{
					temp_parent->right = node->right;
				}
				else
				{
					temp_parent->left = node->right;
				}
			}

			//jezeli node jest korzeniem
			else
			{
				root = node->right;
			}

			temp1->right = temp2;
			if (temp2 != nullptr)
			{
				temp2->parent = temp1;
			}

			temp1->parent = node->right;

			update_bf(node);
		
		}
	}
}


void HashTable_CA::show() const
{
	for (int i = 0; i < capacity; i++)
	{
		if (!tab[i].is_empty)
		{
			cout << "INDEKS [" << i << "]   KLUCZ [" << tab[i].get_key() << "]   WARTOSC [" << tab[i].get_value() << "]";
			if (tab[i].size_BST != 0 )
			{
				cout << "   DRZEWO [" << tab[i].size_BST << " elementowe]" << endl;
				tab[i].show_BST(tab[i].root); 
				cout << endl << endl;
			}
		}
	}
	if (size == 0)
	{
		cout << "Tablica jest pusta.";
	}
	
}

void BST::show_BST(Node_BST* node) const 
{
	if (node == nullptr) 
	{
		//jeœli node jest nullptr, natychmiast zakoñcz funkcjê
		return;
	}

	Node_BST* current = node;
	
	cout << "  KLUCZ [" << current->key << "]  WARTOSC [" << current->value << "]  BF [" << current->bf << "]" << endl;
	show_BST(current->left);
	show_BST(current->right);

	delete current;
}

int  HashTable_CA::capacity_() const
{
	//zwrocenie pojemnosci
	return capacity;
}

int  HashTable_CA::size_() const
{
	//zwrocenie rozmiaru
	return size;
}

void  HashTable_CA::remove(int k)
{
	//znalezie indeksu pod ktorym znajduje sie element do usuniecia
	int i = hash(k);

	tab[i].remove_BST(k);
	if(tab[i].is_empty)
	size--;

}

void BST::remove_BST(int k) {
	Node_BST* current = root;
	Node_BST* parent = nullptr;

	// ZnajdŸ wêze³ do usuniêcia
	while (current != nullptr && current->key != k) {
		parent = current;
		if (k < current->key) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	// Jeœli wêze³ nie zosta³ znaleziony
	if (current == nullptr) {
		return;
	}

	// Wêze³ nie ma potomków
	if (current->left == nullptr && current->right == nullptr) {
		if (current != root) {
			if (parent->left == current) {
				parent->left = nullptr;
			}
			else {
				parent->right = nullptr;
			}
		}
		else {
			root = nullptr;
		}
		delete current;
	}
	// Wêze³ ma jednego potomka
	else if (current->left == nullptr || current->right == nullptr) {
		Node_BST* child = (current->left != nullptr) ? current->left : current->right;

		if (current != root) {
			if (current == parent->left) {
				parent->left = child;
			}
			else {
				parent->right = child;
			}
		}
		else {
			root = child;
		}
		child->parent = parent;
		delete current;
	}
	// Wêze³ ma dwóch potomków
	else {
		Node_BST* successor = current->right;
		Node_BST* successorParent = current;

		while (successor->left != nullptr) {
			successorParent = successor;
			successor = successor->left;
		}

		if (successorParent != current) {
			successorParent->left = successor->right;
			if (successor->right != nullptr) {
				successor->right->parent = successorParent;
			}
			successor->right = current->right;
			current->right->parent = successor;
		}

		if (current != root) {
			if (current == parent->left) {
				parent->left = successor;
			}
			else {
				parent->right = successor;
			}
		}
		else {
			root = successor;
		}

		successor->left = current->left;
		current->left->parent = successor;
		successor->parent = parent;
		delete current;
	}

	size_BST--;
	if (size_BST == 0) 
	{
		is_empty = true;
	}
}










 
