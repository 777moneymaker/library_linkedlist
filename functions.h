#ifndef PROJEKT_11_01_0219_FUNCTIONS_H
#define PROJEKT_11_01_0219_FUNCTIONS_H
using namespace std;

struct Date {  // will be nested struct
	string day;
	string month;
	string year;
};
struct Book {  // main struct for doubly-linked list
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

struct Book* head = NULL; // pointers for next and prev node in list
struct Book* tail = NULL; 
int identificator = 1; // variable that stores id's

void insertBook(string bookTitle, string authorName, string authorSurname, string category){ // node insertion at tail

	struct Book* newBook = new Book; //memory allocation for new node

	newBook->ID = identificator;
	newBook->bookTitle = bookTitle;
	newBook->authorName = authorName;
	newBook->authorSurname = authorSurname; //our data insertion
	newBook->category = category;
	newBook->loanStatus = "Wolna";
	identificator++;

	newBook->next = NULL;
	if (head == NULL) {
		newBook->prev = NULL; 
		head = newBook; //single node is head and also tail 
		tail = newBook;
		return;
	}
	while (tail->next != NULL)
		tail = tail->next; // our step instruction

	tail->next = newBook;
	newBook->prev = tail; //setting up new tail
	tail = newBook;
	return;

}

void deleteNode(struct Book* del) { // procedure for deleting node
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

void deleteItemById(int ID) { //deleting by comparing node's ID's

    if (head == NULL || ID < 0) {
        cout << endl;
        cout << "Nie mozna usunac!" << endl;
        cout << endl;
        return;
    }

    struct Book *temp = head;
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
        cout << "Nie ma ksiazki o podanym indeksie. Sprawdz czy wybrales dobry indeks!" << endl;
        cout << endl;
        return;
    }
    cout << endl;
    cout << "Usunieto!" << endl;
    cout << endl;
    deleteNode(temp); // function inside function
    if (identificator == 1)
        return;
}

void deleteItemByTitle(string title) { //deleting nodes by string(title) compare
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
			cout << "Usunieto!" << endl;
			cout << endl;
			return;
		}
		temp = temp->next;
	}
}

void editItemByTitle(string title) { //compare title and edit if equal
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
	cout << "Wprowadz  nowe dane, lub wcisnij ENTER aby pozostawic stare dane: " << endl;
	cout << "================================================================" << endl;
	cout << "Tytul: ";
	cin.ignore();
	getline(cin, bookTitle, '\n');
	cout << "Imie autora: ";
	getline(cin, authorName, '\n');
	cout << "Nazwisko autora: ";
	getline(cin, authorSurname, '\n');
	cout << "Kategoria: ";
	getline(cin, category, '\n');
	cout << "Dzien wypozyczenia: ";
	getline(cin, loanDay, '\n');
	cout << "Miesiac wypozyczenia: ";
	getline(cin, loanMonth, '\n');    // getline's for reading ENTER's
	cout << "Rok wypozyczenia: ";
	getline(cin, loanYear, '\n');
	cout << "Imie wypozyczajacego: ";
	getline(cin, loanName, '\n');
	cout << "Nazwisko wypozyczajacego: ";
	getline(cin, loanSurname, '\n');
	cout << "Status ksiazki: ";
	getline(cin, loanStatus, '\n');
	cout << "Dodatkowe dane(komentarze): ";
	getline(cin, extraData, '\n');
	cout << endl;
	while (temp) { // data compare 
		if (!(title.compare(temp->bookTitle))) { // if title is equal then go
			if ((bookTitle.compare(valid))) { //if title is not equal then go
				temp->bookTitle = bookTitle;
			}
			if ((authorName.compare(valid))) { //etc for all as above
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

void changeBookStatus(string title) { //book status change by string  compare
	string loanDay, loanMonth, loanYear, loanName, loanSurname, loanStatus;
	string statusFree = "Wolna";
	string statusNfree = "Wypozyczona";
	int count = 0;
	char yn;
	struct Book* temp;
	temp = head;
	while (temp) {
		if (!(title.compare(temp->bookTitle))) { //if title equal then go
			if (!(statusFree.compare(temp->loanStatus))) { // if status is free then do calculations
				count++;
				cout << "Wprowadz nowe dane: \n" << endl;
				cout << "Dzien wypozyczenia: " << endl;
				cin >> loanDay;
				cout << "Miesiac wypozyczenia: " << endl;
				cin >> loanMonth;
				cout << "Rok wypozyczenia: " << endl;
				cin >> loanYear;
				cout << "Imie wypozyczajacego: " << endl;
				cin >> loanName;
				cout << "Nazwisko wypozyczajacego: " << endl;
				cin >> loanSurname;
				cout << "Czy zmienic status na wypozyczona?(y/n)" << endl;
				cin >> yn;
				switch (yn) {
				case 'y': {
					temp->date.year = loanYear;
					temp->date.day = loanDay;
					temp->date.month = loanMonth;
					temp->loanName = loanName;
					temp->loanSurname = loanSurname;
					temp->loanStatus = "Wypozyczona";

					cout << "Zmieniono na \" Wypozyczona\" " << endl;
					return;
				}
				case 'n': {
					cout << "Nastapil powrot do Glownego MENU" << endl;
					return;
				}
				default: {
					cout << "\nWybrales zla opcje. Nastapil powrot do Glownego MENU\n" << endl;
					return;
				}
				}



			}
			else if (!(statusNfree.compare(temp->loanStatus))) { //if status is occupied then do calculations
				char yn;
				count++;
				cout << "Tytul: " << temp->bookTitle << endl;
				cout << "Autor: " << temp->authorName << " " << temp->authorSurname << endl;
				cout << "Wypozyczajacy: " << temp->loanName << " " << temp->loanSurname << endl;
				cout << "Data wypozyczenia: \n" << temp->date.day << " " << temp->date.month << " " << temp->date.year << endl;
				cout << "Czy zmienic status na \"Wolna\"?(y/n)" << endl;
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
					cout << "Nastapil powrot do Glownego MENU" << endl;
					return;
				}
				default:
					cout << "\nWybrales zla opcje! Nastapil powrot do Glownego MENU \n" << endl;
					return;
				}

			}
			else { //if status is other than two above 
                cout << "\nKsiazka ma zly status! Zmien jej status uzywajac opcji edycji danych ksiazki.\n" << endl;
				return;
			}
		}

		temp = temp->next;
	}
	if (count == 0) {
		cout << "\nNie ma ksiazki o podanym tytule lub nazwisku wypozyczajacego!\n" << endl;
	}
}


void printList() { //function used when testing the program
	if (head == NULL) {
		cout << "\nBaza pusta!\n" << endl;
		return;
	}
	struct Book* temp;
	temp = head;
	while (temp) {
		cout << endl;
		cout << "ID: " << temp->ID << endl;
		cout << "Tytul ksiazki: " << temp->bookTitle << endl;
		cout << "Autor: " << temp->authorName << " " << temp->authorSurname << endl;
		cout << "Kategoria: " << temp->category << endl;
		cout << "Data wypozyczenia: " << temp->date.day << " " << temp->date.month << " " << temp->date.year << endl;
		cout << "Wypozyczajacy: " << temp->loanName << " " << temp->loanSurname << endl;
		cout << "Status: " << temp->loanStatus << endl;
		cout << "Dodatkowe dane: " << temp->extraData << endl;
		cout << endl;
		temp = temp->next;
	}
}


void printListByParams(string option) { //printing list by given parameter(title or surname)
	struct Book* temp;
	temp = head;
	int count = 0;
	while (temp) {
		if (!(option.compare(temp->loanSurname))) {
			cout << endl;
			cout << "ID: " << temp->ID << endl;
			cout << "Tytul ksiazki: " << temp->bookTitle << endl;
			cout << "Autor: " << temp->authorName << " " << temp->authorSurname << endl;
			cout << "Kategoria: " << temp->category << endl;
			cout << "Data wypozyczenia: " << temp->date.day << " " << temp->date.month << " " << temp->date.year << endl;
			cout << "Wypozyczajacy: " << temp->loanName << " " << temp->loanSurname << endl;
			cout << "Status: " << temp->loanStatus << endl;
			cout << "Dodatkowe dane: " << temp->extraData << endl;
			cout << endl;
			count++;
		}
		if (!(option.compare(temp->bookTitle))) {
			cout << endl;
			cout << "ID: " << temp->ID << endl;
			cout << "Tytul ksiazki: " << temp->bookTitle << endl;
			cout << "Autor: " << temp->authorName << " " << temp->authorSurname << endl;
			cout << "Kategoria: " << temp->category << endl;
			cout << "Data wypozyczenia: " << temp->date.day << " " << temp->date.month << " " << temp->date.year << endl;
			cout << "Wypozyczajacy: " << temp->loanName << " " << temp->loanSurname << endl;
			cout << "Status: " << temp->loanStatus << endl;
			cout << "Dodatkowe dane: " << temp->extraData << endl;
			cout << endl;
			count++;
		}

		temp = temp->next;
	}

	if (count == 0) { //there is none valid book
		cout << "\nBrak ksiazki o podanym tytule lub nazwisku wypozyczajacego\n" << endl;
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
	string valid = "Wypozyczona";
	int count = 0;
	while (temp) {
		if (!(valid.compare(temp->loanStatus))) {
			cout << endl;
			cout << "ID: " << temp->ID << endl;
			cout << "Tytul ksiazki: " << temp->bookTitle << endl;
			cout << "Autor: " << temp->authorName << " " << temp->authorSurname << endl;
			cout << "Kategoria: " << temp->category << endl;
			cout << "Data wypozyczenia: " << temp->date.day << " " << temp->date.month << " " << temp->date.year << endl;
			cout << "Wypozyczajacy: " << temp->loanName << " " << temp->loanSurname << endl;
			cout << "Status: " << temp->loanStatus << endl;
			cout << "Dodatkowe dane: " << temp->extraData << endl;
			cout << endl;
			count++;
		}


		temp = temp->next;
	}
	if (count == 0) {
		cout << "Brak ksiazek wypozyczonych. Sprawdz czy ksiazki maja wlasciwe statusy!" << endl;
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
		cout << "Blad przy zapisywaniu do pliku." << endl;
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
	string loanDay, string loanMonth, string loanYear, string loanName, string loanSurname, string loanStatus, string
    extraData) { //used in another function (reading from file)
    
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
		cout << "Blad przy odczytywaniu pliku." << endl;
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
	cout << "Pomyslnie wczytano z pliku." << endl;
}

int areMoreBooks(string title) {
    if (head == NULL) {
        return 0;
    }
        struct Book *temp;
        temp = head;
        int count = 0;
        while (temp) {
            if (!(title.compare(temp->bookTitle))) {
                count++;
            }
            temp = temp->next;
        }
        if (count > 1)
            return 1;
        else
            return 0;
    }

void deleteSpecificBook(int id){
    struct Book* temp = head;
    while (temp) {
        if (id == temp->ID) {
            deleteNode(temp);
            cout << endl;
            cout << "Usunieto!" << endl;
            cout << endl;
            return;
        }
        temp = temp->next;
    }
}
void printNodeByTitle(string title){
    struct Book* temp = head;
    while (temp) {
        if (!(title.compare(temp->bookTitle))) {
            cout << endl;
            cout <<"ID: "<<temp->ID<< endl;
            cout<< "Tytul: "<<temp->bookTitle<<endl;
            cout<<"Autor: "<<temp->authorName<<" "<<temp->authorSurname<<endl;
            cout << endl;
            cout<<endl;
        }
        temp = temp->next;
    }
}
int isLoanTitle(string title){
        struct Book* temp = head;
        while (temp) {
            if (!(title.compare(temp->bookTitle))) {
                if(!(temp->loanStatus).compare("Wypozyczona"))
                return 1;
            }
            temp = temp->next;
        }
        return 0;
    }
    int isLoanId(int ID){
        struct Book* temp = head;
        while (temp) {
            if (ID==temp->ID) {
                if(!(temp->loanStatus).compare("Wypozyczona"))
                return 1;
            }
            temp = temp->next;
        }
        return 0;
}
#endif //PROJEKT_11_01_0219_FUNCTIONS_H
