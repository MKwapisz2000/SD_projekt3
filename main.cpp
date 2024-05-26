#include <iostream>
#include <fstream>
#include <chrono>
#include "HashTable_OA.h"
#include "HashTable_CA.h"

using namespace std;

int main()
{
    //..............................OBIEKTY POSZCZEGOLNYCH STRUKTUR...........................................

	//Obiekt klasy - tablica mieszajaca - adresowanie otwarte
    HashTable_OA OA;
	HashTable_CA CA;

    //.......................................................................................................
    


	//..............................WCZYTANIE DANYCH Z PLIKU...............................................
	/*
	// Licznik całkowitego czasu wykonania
	//auto total_time = 0ns;

	// Liczba pomiarów
	//int measurements = 100;

	// Wczytywanie danych z pliku i pomiar czasu 100 razy
	//for (int i = 0; i < 100; ++i)
	//{
	// Wczytywanie danych z pliku
	ifstream plik;
	string nazwa = "dane_2k_pop1.txt";

	plik.open(nazwa, ios::out);
	if (!plik.good())
	{
		cout << "Blad przy otwarciu pliku." << endl;
		return -1;
	}

	int value;
	int key;
	while (plik >> value >> key)
	{
		CA.insert(value, key);
	}
	plik.close();
	*/

	//.....................................................................................................


	
	
	CA.insert(48, 122);
	CA.insert(8, 102);
	//CA.insert(29, 126);
	//CA.insert(1, 10);


	CA.insert(29, 114);
	//CA.insert(1, 6);
	//CA.insert(29, 14);

	CA.insert(120, 51);
	CA.insert(1, 51);

	
	CA.show();
	cout << "rozmiar tablicy: " << CA.size_() << endl;
	cout << "pojemnosc: " << CA.capacity_() << endl;

	

	


	//..................................POMIAR CZASU......................................................
	/*
	// Pomiar czasu dla pojedynczego wywołania funkcji
		auto begin = chrono::high_resolution_clock::now();
		h1.modify_key(3850,121);
		auto end = chrono::high_resolution_clock::now();
		auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);

		// Dodanie czasu do całkowitego czasu wykonania
		total_time += elapsed;

		// Czyszczenie struktury
		OA.clear();

	}

	// Obliczenie średniego czasu wykonania
	auto average_time = total_time / measurements;

	// Wyświetlenie wyniku średniego czasu wykonania
	cout << "Sredni czas wykonania: " << average_time.count() << " nanosekund" << endl;
   */
   //.....................................................................................................
	



    return 0;
}

