#include <iostream>
#include <fstream>
#include <chrono>
#include "HashTable_OA.h"
#include "HashTable_CA.h"
#include "CuckooHshTable.h"

using namespace std;

int main()
{
    //..............................OBIEKTY POSZCZEGOLNYCH STRUKTUR...........................................

	//Obiekt klasy - tablica mieszajaca - adresowanie otwarte
    	HashTable_OA OA;
	HashTable_CA CA;
	CuckooHashTable CH;

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
		CA.insert(value, key);
		CH.insert(value, key);
	}
	plik.close();
	

	//.....................................................................................................

	


	//..................................POMIAR CZASU......................................................
	/*
	// Pomiar czasu dla pojedynczego wywołania funkcji
		auto begin = chrono::high_resolution_clock::now();
		OA.insert(3,123);
 		CA.insert(3,123);
   		CH.insert(3,123);
		auto end = chrono::high_resolution_clock::now();
		auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);

		// Dodanie czasu do całkowitego czasu wykonania
		total_time += elapsed;

		// Czyszczenie struktury
		OA.clear();
		CA.clear();
		CH.clear();

	}

	// Obliczenie średniego czasu wykonania
	auto average_time = total_time / measurements;

	// Wyświetlenie wyniku średniego czasu wykonania
	cout << "Sredni czas wykonania: " << average_time.count() << " nanosekund" << endl;
   */
   //.....................................................................................................
	



   //..................................MENU...............................................................
	
	int zmienna1;
	char zmienna2;
	int e;
	int k;

	cout << "TABLICA MIESZAJACA:" << endl
		<< "[1] Adresowanie otwarte" << endl
		<< "[2] Adresowanie zamkniete ze zbalansowanym BST" << endl
		<< "[3] Cuckoo hashing" << endl;
	cout << "Przechodze do struktury numer: ";
	cin >> zmienna1;
	system("cls");
	switch (zmienna1)
	{
	case 1:
	{
		cout << "Wybierz funkcje z ktorej chcesz skorzystac:" << endl
			<< "[a] insert(e, k)" << endl
			<< "[b] remove(k)" << endl;

		cout << "Przechodze do funkcji: ";
		cin >> zmienna2;

		switch (zmienna2)
		{
		case 'a':
		{
			cout << "Podaj wartosc elementu ktory chcesz dodac oraz jego klucz: ";
			cin >> e >> k;
			OA.insert(e, k);
			cout << endl;
			system("cls");
			cout << "Obecny rozmiar tablicy: " << OA.size_() << endl;
			OA.show();

			break;
		}

		case 'b':
		{
			cout << "Podaj klucz elementu ktory chcesz usunac: ";
			cin >> k;
			OA.remove(k);
			cout << endl;
			system("cls");
			cout << "Obecny rozmiar tablicy: " << OA.size_() << endl;
			OA.show();

			break;
		}

		default:
			break;
		}

	}

	case 2:
	{
		cout << "Wybierz funkcje z ktorej chcesz skorzystac:" << endl
			<< "[a] insert(e, k)" << endl
			<< "[b] remove(k)" << endl;

		cout << "Przechodze do funkcji: ";
		cin >> zmienna2;

		switch (zmienna2)
		{
		case 'a':
		{
			cout << "Podaj wartosc elementu ktory chcesz dodac oraz jego klucz: ";
			cin >> e >> k;
			CA.insert(e, k);
			cout << endl;
			system("cls");
			cout << "Obecny rozmiar tablicy: " << CA.size_() << endl;
			CA.show();

			break;
		}

		case 'b':
		{
			cout << "Podaj klucz elementu ktory chcesz usunac: ";
			cin >> k;
			CA.remove(k);
			cout << endl;
			system("cls");
			cout << "Obecny rozmiar tablicy: " << CA.size_() << endl;
			CA.show();

			break;
		}

		default:
			break;
		}

	}


	case 3:
	{
		cout << "Wybierz funkcje z ktorej chcesz skorzystac:" << endl
			<< "[a] insert(e, k)" << endl
			<< "[b] remove(k)" << endl;

		cout << "Przechodze do funkcji: ";
		cin >> zmienna2;

		switch (zmienna2)
		{
		case 'a':
		{
			cout << "Podaj wartosc elementu ktory chcesz dodac oraz jego klucz: ";
			cin >> e >> k;
			CH.insert(e, k);
			cout << endl;
			system("cls");
			cout << "Obecny rozmiar tablicy: " << CH.size_() << endl;
			CH.show();

			break;
		}

		case 'b':
		{
			cout << "Podaj klucz elementu ktory chcesz usunac: ";
			cin >> k;
			CH.remove(k);
			cout << endl;
			system("cls");
			cout << "Obecny rozmiar tablicy: " << CH.size_() << endl;
			CH.show();

			break;
		}

		default:
			break;
		}


	}
	}
	
	//.....................................................................................................


    return 0;
}

