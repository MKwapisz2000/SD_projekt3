#include <iostream>
#include <fstream>
#include <chrono>
#include "HashTable_OA.h"

using namespace std;

int main()
{
    //..............................OBIEKTY POSZCZEGOLNYCH STRUKTUR...........................................

	//Obiekt klasy - tablica mieszajaca - adresowanie otwarte
    HashTable_OA OA;

    //.......................................................................................................
    


	//..............................WCZYTANIE DANYCH Z PLIKU...............................................

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
		OA.insert(value, key);
	}
	plik.close();


	//.....................................................................................................


	OA.show();
	OA.remove(6622);
	cout <<endl<<OA.size_();
	
	


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
	/*
    OA.insert(15, 6);
    OA.insert(25, 6);
    OA.insert(325, 121);
    OA.insert(205, 61);
    OA.insert(3025, 121);
    OA.insert(1, 22);

    //OA.insert(25, 43);
    
    OA.show();
    cout << "--------------------" << endl;
    //OA.remove(6);
    cout << endl;
    //OA.show();
    cout << endl << OA.cap();
  */




    return 0;
}

