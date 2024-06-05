#include <iostream>
#include <fstream>
using namespace std;

string fname, lname;
char gender[1];
fstream file;	


class Census {
public:
	void csMenu();
	void addRecord();
	void displayRecords();
	void searchRecord();
};

void Census::csMenu() {
	system("cls");
	cout << "___________________________" << endl;
	cout << "         Main Menu                " << endl;
	cout << "___________________________" << endl;
	cout << " 1 - Add Record." << endl;
	cout << " 2 - Dispaly All Records." << endl;
	cout << " 3 - Search For A Record." << endl;
	cout << " 4 - Exit." << endl;
	cout << "___________________________" << endl;
}

void Census::addRecord() {
	system("cls");
	cout << "___________________________" << endl;
	cout << "       Add New Record." << endl;
	cout << "___________________________" << endl;
	cout << "Enter First Name: ";
	cin >> fname;
	cout << "Enter Last Name: ";
	cin >> lname;
	cout << "Enter Gender [M/F]: ";
	cin >> gender;
	file.open("database.txt", ios::out | ios::app);
	file << fname << " " << lname << " " << gender << endl; 
	file.close();
}

void Census::displayRecords() {
	system("cls");
	cout << "___________________________" << endl;
	cout << "       All Records." << endl;
	cout << "___________________________" << endl;
	cout << "" << endl;
	file.open("database.txt", ios::in);
	if (!file)
	{
		cout << "Database Failed To Open!" << endl;
	} else {
		cout << "First Name\t\tLast Name\t\tGender" << endl;
		file >> fname >> lname >> gender; 
		while(!file.eof()) {
			cout << fname << "\t\t\t" << lname << "\t\t\t" << gender << endl; 
			file >> fname >> lname >> gender; 
		}
		system("pause");
		file.close();
	}
} 



void Census::searchRecord() {
	int count = 0;
	string fname2;
	system("cls");
	cout << "___________________________" << endl;
	cout << "       Search Record." << endl;
	cout << "___________________________" << endl;
	cout << "" << endl;
	file.open("database.txt", ios::in);
	if (!file) {
		cout << "Database Failed To Open!" << endl;
	} else {
		cout << "Enter Person's First Name: ";
		cin >> fname2;
		file >> fname >> lname >> gender; 
		while(!file.eof()) {
			if (fname == fname2) {
				cout << "First Name: " << fname << endl;
				cout << "Last Name: " << lname << endl;
				cout << "Gender: " << gender << endl;
				count = 1;
				break;
			}
			file >> fname >> lname >> gender; 
		}
		if (count == 0) {
			cout << "No Record Not Found!" << endl;
		}
		system("pause");
		file.close();
	}
}



Census census;

int main() {
	system("color f0");
	int option, rep = 1;
	char var;
	while(rep) {
		census.csMenu();
		cout << "Enter Prefered Option: ";
		cin >> option;
		if (option == 1) {
			do {
				census.addRecord();
				cout << endl;
				cout << "ADD Record Again [y/n]:";
				cin >> var ;
			} while(var == 'y');
		} else if (option == 2) {
			census.displayRecords();
		} else if (option == 3) {
			census.searchRecord();
		} else if (option == 4) {
			cout << endl;
			return 0;
		} else {
			cout << "Invalid Option Selected!" << endl;
			cout << endl;
		}
	}
	return 0;
}

