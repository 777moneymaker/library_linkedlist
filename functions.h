#ifndef PROJEKT_11_01_0219_FUNCTIONS_H
#define PROJEKT_11_01_0219_FUNCTIONS_H
using namespace std;

struct Date {
	string day;
	string month;
	string year;
};
struct Book {
	int ID;
	string bookTitle;
	string authorName;
	string authorSurname;
	string category;
	struct Date date;
	string loanName;
	string loanSurname;
	string loanStatus;
	string extraData;
	struct Book* next;
	struct Book* prev;
};

struct Book* head = NULL;
struct Book* tail = NULL;
int identificator = 1;

void insertBook(string bookTitle, string authorName, string authorSurname, string category) {

	struct Book* newBook = new Book;

	newBook->ID = identificator;
	newBook->bookTitle = bookTitle;
	newBook->authorName = authorName;
	newBook->authorSurname = authorSurname;
	newBook->category = category;
	newBook->loanStatus = "Wolna";
	identificator++;

	newBook->next = NULL;
	if (head == NULL) {
		newBook->prev = NULL;
		head = newBook;
		tail = newBook;
		return;
	}
	while (tail->next != NULL)
		tail = tail->next;

	tail->next = newBook;
	newBook->prev = tail;
	tail = newBook;
	return;

}

void deleteNode(struct Book* del) {
	if (head == NULL || del == NULL)
		return;
	if (head == del)
		head = del->next;
	if (tail == del)
		tail = del->prev;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	delete(del);
	return;
}

void deleteItemById(int ID) {

	if (head == NULL || ID < 0) {
		cout << endl;
		cout << "Nie mozna usun¹æ!" << endl;
		cout << endl;
		return;
	}

	struct Book* temp = head;
	int count = 0;
	while (temp != NULL) {
		if (temp->ID == ID) {
			count++;
			break;
		}
		temp = temp->next;
	}
	if (count == 0) {
		cout << endl;
		cout << "Nie ma ksi¹¿ki o podanym indeksie. SprawdŸ czy wybra³eœ dobry indeks!" << endl;
		cout << endl;
		return;
	}
	cout << endl;
	cout << "Usuniêto!" << endl;
	cout << endl;
	deleteNode(temp);
	if (identificator == 1)
		return;
	identificator--;

}

void deleteItemByTitle(string title) {
	if (head == NULL) {
		cout << endl;
		cout << "Baza pusta!" << endl;
		cout << endl;
		return;
	}
	struct Book* temp;
	temp = head;
	while (temp) {
		if (!(title.compare(temp->bookTitle))) {
			deleteNode(temp);
			cout << endl;
			cout << "Usuniêto!" << endl;
			cout << endl;
			return;
		}
		temp = temp->next;
	}
}

void editItemByTitle(string title) {
	if (head == NULL) {
		cout << endl;
		cout << "Baza pusta!";
		cout << endl;
		return;
	}

	struct Book* temp;
	temp = head;
	string valid, bookTitle, authorName, authorSurname, category, loanDay, loanMonth, loanYear, loanName, loanSurname, loanStatus, extraData;
	cout << "================================================================" << endl;
	cout << "WprowadŸ nowe dane, lub wciœnij ENTER aby pozostawiæ stare dane: " << endl;
	cout << "================================================================" << endl;
	cout << "Tytu³: ";
	cin.ignore();
	getline(cin, bookTitle, '\n');
	cout << "Imiê autora: ";
	getline(cin, authorName, '\n');
	cout << "Nazwisko autora: ";
	getline(cin, authorSurname, '\n');
	cout << "Kategoria: ";
	getline(cin, category, '\n');
	cout << "Dzieñ wypo¿yczenia: ";
	getline(cin, loanDay, '\n');
	cout << "Miesi¹c wypo¿yczenia: ";
	getline(cin, loanMonth, '\n');
	cout << "Rok wypo¿yczenia: ";
	getline(cin, loanYear, '\n');
	cout << "Imiê wypo¿yczaj¹cego: ";
	getline(cin, loanName, '\n');
	cout << "Nazwisko wypo¿yczaj¹cego: ";
	getline(cin, loanSurname, '\n');
	cout << "Status ksi¹¿ki: ";
	getline(cin, loanStatus, '\n');
	cout << "Dodatkowe dane(komentarze): ";
	getline(cin, extraData, '\n');
	cout << endl;
	while (temp) {
		if (!(title.compare(temp->bookTitle))) {
			if ((bookTitle.compare(valid))) {
				temp->bookTitle = bookTitle;
			}
			if ((authorName.compare(valid))) {
				temp->authorName = authorName;
			}
			if ((authorSurname.compare(valid))) {
				temp->authorSurname = authorSurname;
			}
			if ((category.compare(valid))) {
				temp->category = category;
			}
			if ((loanYear.compare(valid)) || (loanDay.compare(valid)) || (loanMonth.compare(valid))) {
				temp->date.day = loanDay;
				temp->date.month = loanMonth;
				temp->date.year = loanYear;
			}
			if ((loanName.compare(valid))) {
				temp->loanName = loanName;
			}
			if ((loanSurname.compare(valid))) {
				temp->loanSurname = loanSurname;
			}
			if ((loanStatus.compare(valid))) {
				temp->loanStatus = loanStatus;
			}
			if ((extraData.compare(valid))) {
				temp->extraData = extraData;
			}

		}
		temp = temp->next;
	}
	return;
}

void changeBookStatus(string title) {
	string loanDay, loanMonth, loanYear, loanName, loanSurname, loanStatus;
	string statusFree = "Wolna";
	string statusNfree = "Wypo¿yczona";
	int count = 0;
	char yn;
	struct Book* temp;
	temp = head;
	while (temp) {
		if (!(title.compare(temp->bookTitle))) {
			if (!(statusFree.compare(temp->loanStatus))) {
				count++;
				cout << "WprowadŸ nowe dane: \n" << endl;
				cout << "Dzieñ wypo¿yczenia: " << endl;
				cin >> loanDay;
				cout << "Miesi¹c wypo¿yczenia: " << endl;
				cin >> loanMonth;
				cout << "Rok wypo¿yczenia: " << endl;
				cin >> loanYear;
				cout << "Imiê wypo¿yczaj¹cego: " << endl;
				cin >> loanName;
				cout << "Nazwisko wypo¿yczaj¹cego: " << endl;
				cin >> loanSurname;
				cout << "Czy zmieniæ status na wypo¿yczon¹?(y/n)" << endl;
				cin >> yn;
				switch (yn) {
				case 'y': {
					temp->date.year = loanYear;
					temp->date.day = loanDay;
					temp->date.month = loanMonth;
					temp->loanName = loanName;
					temp->loanSurname = loanSurname;
					temp->loanStatus = "Wypo¿yczona";

					cout << "Zmieniono na \" Wypo¿yczona\" " << endl;
					return;
				}
				case 'n': {
					cout << "Nast¹pi³ powrót do G³ównego MENU" << endl;
					return;
				}
				default: {
					cout << "\nWybra³eœ z³¹ opcjê. Nast¹pi³ powrót do G³ównego MENU\n" << endl;
					return;
				}
				}



			}
			else if (!(statusNfree.compare(temp->loanStatus))) {
				char yn;
				count++;
				cout << "Tytu³: " << temp->bookTitle << endl;
				cout << "Autor: " << temp->authorName << " " << temp->authorSurname << endl;
				cout << "Wypo¿yczaj¹cy: " << temp->loanName << " " << temp->loanSurname << endl;
				cout << "Data wypo¿yczenia: \n" << temp->date.day << " " << temp->date.month << " " << temp->date.year << endl;
				cout << "Czy zmieniæ status na \"Wolna\"?(y/n)" << endl;
				cin >> yn;
				switch (yn) {
				case 'y': {
					temp->date.year = "";
					temp->date.day = "";
					temp->date.month = "";
					temp->loanName = "";
					temp->loanSurname = "";
					temp->loanStatus = "Wolna";
					return;
				}
				case 'n': {
					cout << "Nast¹pi³ powrót do G³ównego MENU" << endl;
					return;
				}
				default:
					cout << "\nWybraleœ z³¹ opcjê! Nast¹pi³ powrót do G³ównego MENU \n" << endl;
					return;
				}

			}
			else {
				cout << "\nKsi¹¿ka ma z³y status! Zmieñ jej status u¿ywaj¹c opcji edycji danych ksi¹¿ki.\n" << endl;
				return;
			}
		}

		temp = temp->next;
	}
	if (count == 0) {
		cout << "\nNie ma ksi¹¿ki o podanym tytule lub nazwisku wypo¿yczaj¹cego!\n" << endl;
	}
}


//Dodatkowa funkcja u¿ywana tylko w czasie tworzenia i testowania programu
void printList() {
	if (head == NULL) {
		cout << "\nBaza pusta!\n" << endl;
		return;
	}
	struct Book* temp;
	temp = head;
	while (temp) {
		cout << endl;
		cout << "ID: " << temp->ID << endl;
		cout << "Tytu³ ksi¹¿ki: " << temp->bookTitle << endl;
		cout << "Autor: " << temp->authorName << " " << temp->authorSurname << endl;
		cout << "Kategoria: " << temp->category << endl;
		cout << "Data wypozyczenia: " << temp->date.day << " " << temp->date.month << " " << temp->date.year << endl;
		cout << "Wypozyczaj¹cy: " << temp->loanName << " " << temp->loanSurname << endl;
		cout << "Status: " << temp->loanStatus << endl;
		cout << "Dodatkowe dane: " << temp->extraData << endl;
		cout << endl;
		temp = temp->next;
	}
}


void printListByParams(string option) {
	struct Book* temp;
	temp = head;
	int count = 0;
	while (temp) {
		if (!(option.compare(temp->loanSurname))) {
			cout << endl;
			cout << "ID: " << temp->ID << endl;
			cout << "Tytu³ ksi¹¿ki: " << temp->bookTitle << endl;
			cout << "Autor: " << temp->authorName << " " << temp->authorSurname << endl;
			cout << "Kategoria: " << temp->category << endl;
			cout << "Data wypozyczenia: " << temp->date.day << " " << temp->date.month << " " << temp->date.year << endl;
			cout << "Wypozyczaj¹cy: " << temp->loanName << " " << temp->loanSurname << endl;
			cout << "Status: " << temp->loanStatus << endl;
			cout << "Dodatkowe dane: " << temp->extraData << endl;
			cout << endl;
			count++;
		}
		if (!(option.compare(temp->bookTitle))) {
			cout << endl;
			cout << "ID: " << temp->ID << endl;
			cout << "Tytu³ ksi¹¿ki: " << temp->bookTitle << endl;
			cout << "Autor: " << temp->authorName << " " << temp->authorSurname << endl;
			cout << "Kategoria: " << temp->category << endl;
			cout << "Data wypozyczenia: " << temp->date.day << " " << temp->date.month << " " << temp->date.year << endl;
			cout << "Wypozyczaj¹cy: " << temp->loanName << " " << temp->loanSurname << endl;
			cout << "Status: " << temp->loanStatus << endl;
			cout << "Dodatkowe dane: " << temp->extraData << endl;
			cout << endl;
			count++;
		}

		temp = temp->next;
	}

	if (count == 0) {
		cout << "\nBrak ksi¹¿ki o podanym tytule lub nazwisku wypo¿yczaj¹cego\n" << endl;
	}

}

void printListByTitle() {
	struct Book* temp;
	if (head == NULL) {
		cout << "\nBaza pusta!\n" << endl;
		return;
	}
	temp = head;
	while (temp) {

		cout << "ID #" << temp->ID << ": " << temp->bookTitle << endl;
		cout << endl;
		temp = temp->next;
	}
}

void printListByLoan() {
	if (head == NULL) {
		cout << "Baza pusta!" << endl;
		cout << endl;
		return;
	}
	struct Book* temp;
	temp = head;
	string valid = "Wypo¿yczona";
	int count = 0;
	while (temp) {
		if (!(valid.compare(temp->loanStatus))) {
			cout << endl;
			cout << "ID: " << temp->ID << endl;
			cout << "Tytu³ ksi¹¿ki: " << temp->bookTitle << endl;
			cout << "Autor: " << temp->authorName << " " << temp->authorSurname << endl;
			cout << "Kategoria: " << temp->category << endl;
			cout << "Data wypozyczenia: " << temp->date.day << " " << temp->date.month << " " << temp->date.year << endl;
			cout << "Wypozyczaj¹cy: " << temp->loanName << " " << temp->loanSurname << endl;
			cout << "Status: " << temp->loanStatus << endl;
			cout << "Dodatkowe dane: " << temp->extraData << endl;
			cout << endl;
			count++;
		}


		temp = temp->next;
	}
	if (count == 0) {
		cout << "Brak ksi¹¿ek wypo¿yczonych. SprawdŸ czy ksia¿ki maj¹ w³aœciwe statusy!" << endl;
		return;
	}

}

void saveToFile(string filename) {
	struct Book* temp;
	temp = head;
	ofstream myfile;
	myfile.open(filename.c_str());
	myfile.clear();
	if (myfile.fail()) {
		cout << "B³¹d przy zapisywaniu do plliku." << endl;
		return;
	}
	while (temp) {
		myfile << temp->ID << endl;
		myfile << temp->bookTitle << endl;
		myfile << temp->authorName << endl;
		myfile << temp->authorSurname << endl;
		myfile << temp->category << endl;
		myfile << temp->date.day << " " << temp->date.month << " " << temp->date.year << endl;
		myfile << temp->loanName << " " << temp->loanSurname << endl;
		myfile << temp->loanStatus << endl;
		myfile << temp->extraData << endl;
		myfile << endl;
		temp = temp->next;
	}
	myfile.close();
	cout << "Zapisano do pliku!" << endl;
}

void insertBookWithAll(int ID, string bookTitle, string authorName, string authorSurname, string category,
	string loanDay, string loanMonth, string loanYear, string loanName, string loanSurname, string loanStatus, string extraData) {

	struct Book* newBook = new Book;

	newBook->ID = ID;
	newBook->bookTitle = bookTitle;
	newBook->authorName = authorName;
	newBook->authorSurname = authorSurname;
	newBook->category = category;
	newBook->loanStatus = loanStatus;
	newBook->date.month = loanMonth;
	newBook->date.year = loanYear;
	newBook->date.day = loanDay;
	newBook->loanName = loanName;
	newBook->loanSurname = loanSurname;
	newBook->extraData = extraData;
	identificator++;
	newBook->next = NULL;
	if (head == NULL) {
		newBook->prev = NULL;
		head = newBook;
		tail = newBook;
		return;
	}
	while (tail->next != NULL)
		tail = tail->next;

	tail->next = newBook;
	newBook->prev = tail;
	tail = newBook;
	return;
}

void readFromFile(string filename) {
	struct Book* temp;
	temp = head;
	while (temp) {
		deleteNode(temp);
		temp = temp->next;
	}
	ifstream myfile;
	myfile.open(filename.c_str());
	if (myfile.fail()) {
		cout << "B³¹d przy odczytywaniu pliku." << endl;
	}
	while (!(myfile.eof())) {
		string bookTitle, authorName, authorSurname, category, loanDay, loanMonth, loanYear, loanName, loanSurname, loanStatus, extraData;
		int ID;
		myfile >> ID;
		myfile >> bookTitle;
		myfile >> authorName;
		myfile >> authorSurname;
		myfile >> category;
		myfile >> loanDay >> loanMonth >> loanYear;
		myfile >> loanName;
		myfile >> loanSurname;
		myfile >> loanStatus;
		myfile >> extraData;
		insertBookWithAll(ID, bookTitle, authorName, authorSurname, category, loanDay, loanMonth, loanYear, loanName, loanSurname, loanStatus, extraData);

	}
	myfile.close();
	cout << "Pomyœlnie wczytano z pliku." << endl;
}
#endif //PROJEKT_11_01_0219_FUNCTIONS_H
