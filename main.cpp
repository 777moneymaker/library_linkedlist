// Created by Milosz Chodkowski

﻿#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string> //bunch of headers
#include <fstream>
#include"functions.h"
#include <locale.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "polish");
	cout << "Wstępne informacje!: \nksiążka wypożyczona ma status \"Wypożyczona\", a książka dostępna ma status \"Wolna\".\n"
		"Każda nowo dodana książka ma status \"Wolna\".\nTytuły należy wpisywać bez spacji"
		"\nŻyczę miłego użytkowania\n\n" << endl; //some info about the program

	char choice;
	while (1) {
		cout << "1) Dodaj nową książkę\n"
			"2) Usuń książkę\n"
			"3) Edytuj dane książki\n" //MENU
			"4) Zmień status książki.\n"
			"5) Wyszukaj książkę\n"
			"6) Wyświetl bazę po tytułach\n"
			"7) Wyświetl książki wypożyczone\n"
			"8) Zapisz do pliku\n"
			"9) Odczytaj z pliku\n"
			"X) Koniec pracy" << endl;
		cout << endl;
		cout << "Wybierz opcję: ";
		cout << endl;
		cin >> choice;
		switch (choice) {
		NEWBOOK: case '1': {
			string bookTitle, authorsName, authorsSurname, category;
			cout << "Podaj tytuł książki, dane autora, oraz kategorię: " << endl;
			cout << "Tytuł: ";
			cin >> bookTitle;
			cout << "Imię autora: ";
			cin >> authorsName;
			cout << "Nazwisko autora: ";
			cin >> authorsSurname;
			cout << "Kategoria: ";
			cin >> category;
			insertBook(bookTitle, authorsName, authorsSurname, category);
			cout << endl;
			cout << "Dodano nową książkę! Czy chcesz dodać kolejną pozycję (y/n)?: ";
			cout << endl;
			char yn;
			cin >> yn;
			switch (yn) {
			case 'y': {
				goto NEWBOOK;
			}
			case 'n': {
				cout << endl;
				cout << "Nastąpił powrót do Głównego MENU";
				cout << endl;
				break;
			}
			default: {
				cout << "Wybrałeś złą opcję!Nastąpił powrót do Głównego Menu" << endl;
				break;
			}
			}


			break;
		}
		case '2': {
			char it;
			cout << "Czy chcesz usunąć książkę po ID, czy po tytule?(i/t): ";
			cin >> it;
			if (it == 'i') {
				int id;
				cout << "Wprowadź ID książki którą chcesz usunąć: ";
				cin >> id;
				cout << endl;
				deleteItemById(id);
			}
			else if (it == 't') {
				string title;
				cout << "Wprowadź tytuł książki którą chcesz usunąć: ";
				cin >> title;
				cout << endl;
				deleteItemByTitle(title);
			}
			break;
		}
		case '3': {
			string title;
			cout << "Wprowadź tytuł  książki, którą chcesz edytować: ";
			cin >> title;
			cout << endl;
			editItemByTitle(title);
			break;

		}
		case '4': {
			string title;
			cout << "Wprowadź tytuł książki, której status chcesz zmienić: " << endl;
			cin >> title;
			cout << endl;
			changeBookStatus(title);
			cout << endl;
			break;

		}
		case '5': {
			cout << "Wprowadź tytuł książki którą chcesz wyszukać lub nazwisko wypożyczającego: ";
			string option;
			cin >> option;
			printListByParams(option);
			break;

		}
		case '6': {
			cout << endl;
			printListByTitle();
			break;
		}
		case '7': {
			cout << endl;
			printListByLoan();
			break;
		}
		case '8': {
			cout << "Podaj nazwę pliku txt wg podanego wzorca - nazwapliku.txt: ";
			string filename;
			cin >> filename;
			saveToFile(filename);
			break;
		}
		case '9': {

			cout << "Podaj nazwę pliku txt wg podanego wzorca - nazwapliku.txt: ";
			string filename;
			cin >> filename;
			readFromFile(filename);
			break;
		}
		case 'x': {
			return 0;
		}
		case 'X': {
			return 0;
		}
		default: {
			cout << "Wybrałeś złą opcję! Dostępna lista opcji jest wyświetlana po każdej zakończonej operacji." << endl;
		}



		}
	}
}
