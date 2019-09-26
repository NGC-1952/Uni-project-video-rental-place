#include "pch.h"
#include "Customer.h"


Customer::Customer()
{
}

Customer::~Customer()
{
}

void Customer::Register() {
	fstream file;

	system("CLS");
	file.open("user_data.txt", ios::out | ios::in |ios::app);

	cout << " * * *     Welcome to registration     * * * \n\n";

	cin.ignore();
	cout << "Enter your name: ";			cin >> name;			file << letterCheck(&name) << " ";
	cout << "\nEnter your surname: ";		cin >> surname;			file << letterCheck(&surname) << " ";
	cout << "\nEnter your town: ";			cin >> town;			file << letterCheck(&town) << " ";
	cout << "\nEnter your mail: ";			cin >> mail;			file << mailCheck(&mail) << " ";
	cout << "\nEnter code address:";		cin >> codeAddress;		file << codeCheck(&codeAddress) << " ";
	cout << "\nEnter your home number: ";	cin >> homeNumber;		file << numberCheck(cin, &homeNumber) << " ";
	cout << "\nEnter your login: ";			cin >> login;			file << loginCheck(&login, file) << " ";
	cout << "\nEnter your password: ";								file << getPassword() << endl;

	file.close();
}

int Customer::numberCheck(istream &stream, int* number) {
	while (!stream) {

		cout << "It's not a number!";
		cout << "\nTry again: ";

		stream.clear();
		stream.ignore();

		stream >> *number;
	}
	return *number;
}

string Customer::letterCheck(string * word) {
	bool isNumber = false;
	
	while (!isNumber) {
		int number = 0;
		int length = (*word).length();

		for (int i = 0; i < length; i++) {

			if (!(int((*word)[i]) > 64 && int((*word)[i]) < 123)) {

				cout << "The error occured, write the proper word!" << endl;
				cin >> *word;

				number++;
				break;
			}
		}

		if (number == 0) isNumber = true;
	}

	std::toupper((*word)[0]);

	return *word;
}

string Customer::mailCheck(string * mail) {

	bool isApe = false;
	bool isDot = false;

	do {
		int length = (*mail).length();

		for (int i = 0; i < length; i++) {

			if ((*mail)[i] == '@') isApe = true;
			
			if ((*mail)[i] == '.') isDot = true;
			
		}

		if (!(isApe && isDot)) {

			cout << "An error occured, write again: ";
			cin >> *mail;

			isApe = false;
			isDot = false;
		}

	} while (!(isApe && isDot));

	return *mail;
}

string Customer::codeCheck(string * code) {
	int number = 1;
	
	while (number != 0) {

		number = 0; 
		int length = (*code).length();

		for (int i = 0; i < length; i++) {

			if ((*code)[i] < 48 || (*code)[i] > 57) {

				cout << "The code needs to contain only numbers! Try again: ";
				cin >> *code;

				number++;
				break;
			}
		}
	}

	return *code;
}

string Customer::loginCheck(string * login, fstream & f) {

	string nam, sur, town, mail, code, log, pass;
	int home;
	bool isNotRepeated = true;
	bool isRepeated = false;

	if (f.is_open()) {
		while (isNotRepeated) {

			isNotRepeated = true;
			isRepeated = false;

			f.clear();
			f.seekg(0, ios::beg);

			while (f >> nam >> sur >> town >> mail >> code >> home >> log >> pass) {

				if ((*login) == log) {

					cout << "There's somebody with that login, try another one." << endl;
					cin >> *login;

					isRepeated = true;
					break;
				}
				if (!isRepeated) isNotRepeated = false; 
				
			}
		}
	}
	else cout << "Couldn't open the file!"; 

	return *login;
}

string Customer::getPassword() {

	string password = "";
	char c = '0';
	bool movedCursor = false;

	while (c != 13) {

		c = _getch();

		if (c == 8) {
			password.pop_back();
			cout << "\b ";

			movedCursor = true;
		}
		else {
			password += c;

			if (movedCursor) cout << "\b*";
			else cout << '*';

			movedCursor = false;
		}
	}

	return password;
}

bool Customer::Logged() { return isLogged; }

void Customer::logIn() {

	fstream file;
	string enteredLog;
	string enteredPass = "";
	string nam, sur, town, mail, code, log, pass;
	char c = '0';
	bool movedCursor = false;
	int what = 1;
	int home;

	file.open("user_data.txt", ios::out);

	cout << "Enter your login: ";
	cin >> enteredLog;
	cout << endl;
	cout << "Enter your password: ";

	while (what == 1) {

		while (c != 13) {

			c = _getch();

			if (c == 8) {

				enteredPass.pop_back();
				cout << "\b ";

				movedCursor = true;
			}
			else {

				enteredPass += c;

				if (movedCursor) cout << "\b*";
				else cout << '*';

				movedCursor = false;
			}
		}


		if (file.is_open()) {

			while (file >> nam >> sur >> town >> mail >> code >> home >> log >> pass) {

				if (enteredLog == login && enteredPass == pass) {

					cout << "There's somebody with that login, try another one." << endl;
					isLogged = true;
					break;
				}
			}
		}
		else cout << "Couldn't open the file!";

		if (!isLogged) {

			cout << "Sorry, your entered data doesn't match our database. What do you want to do?" << endl;
			cout << " 1 - try again, 2 - go back to main menu." << endl;
			cin >> what;

			while (what != 1 || what != 2) {

				cout << "Incorrect value, try again!" << endl;
				cin >> what;
			}
		}
	}

	file.close();
}

void Customer::logOut() {
	if (isLogged) {
		isLogged = false;
		cout << "Now you're logged out!" << endl;
	}
	else cout << "You are already logged out!" << endl;
}

void Customer::Rent(Device dev) {

	fstream file;
	int days;

	system("CLS");

	file.open("rents.txt", ios::out | ios::in | ios::app);

	cin.ignore();

	file << login << " ";
	file << dev.getName() << " ";

	cout << "For how many days would you like ten the device?" << endl;
	cin >> days;

	while (days > 250 || days < 1) {
		cout << "We cannot rent for this amount of days, choose a number between 1 and 250" << endl;
		cin >> days;
	}

	dev.setDaysRented(days);

	cout << "The device is rented!";

	file.close();
}


