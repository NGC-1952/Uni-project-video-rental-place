#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include "Customer.h"
#include "conio.h"

using namespace std; 
using namespace cv;

int optionList();
void Browse(Device tab[3]);
void Rent(Customer cus, Device tab[3]);

int main(){

	bool exit = 0;
	int option;

	Device sonyBody(33, true, "sonyBody.txt", "sonyBody.jpg", "Sony Body");
	Device sony(22, true, "sony.txt", "sony.jpeg", "Sony");
	Device panasonic(55, true, "panasonic.txt", "panasonic.jpg", "Panasonic");
	Device devices[3] = { sonyBody, sony, panasonic };

	Customer c;
	
	while (!exit) {

		system("CLS");

		cout << "  Welcome to CamRent!\n";
		cout << "  The best place to rent cinematic equipment for your movies!\n";
		
		option = optionList();
	
		cin.ignore(0);

		switch (option) {
		case 1: Rent(c, devices);
			break;
		case 2: c.Register();
			break;
		case 3: Browse(devices);
			break;
		case 4: c.logIn();
			break;
		case 5: c.logOut();
			break;
		case 6: exit = 1;
			cout << "Thank you for the visit!";
			break;
		default: cout << "There's no such option!";
		}
	}

	waitKey(0);
	return 0;
}

int optionList() {
	int opt;

	cout << "\n           -- MENU --             \n\n";
	cout << "   -  Rent video equipment    -  (1)\n";
	cout << "   -  Register as a customer  -  (2)\n";
	cout << "   -  Browse devices          -  (3)\n";
	cout << "   -  Log in                  -  (4)\n";
	cout << "   -  Log out                 -  (5)\n";
	cout << "   -  Exit                    -  (6)\n";

	cout << "\n  What would you like to do?\n";
	cin >> opt;

	while (!(opt < 7 && opt > 0)) cin >> opt;

	return opt;
}

void Browse(Device tab[3]) {
	system("CLS");

	cout << "You can browse our devices here!" << endl;
	cout << "To stop browsing click x.\n\n\n" << endl;
	
	bool browsing = true;
	char c;
	int i = 0;

	tab[0].getParameters(); 

	while (browsing) {

		switch (c = _getch()) {
		case 77:                                    //Key Right
			if (i == 2) i = 0;
			else i++;

			system("CLS");
			tab[i].getParameters();
			break;

		case 75:                                    //Key Left
			if (i == 0) i = 2;
			else i--;

			system("CLS");
			tab[i].getParameters();
			break;

		case 'x':
			browsing = false;
			break;

		default:
			cout << "No such command!" << endl;
			break;
		}
	}
}

void Rent(Customer cus, Device tab[3]) {

	int choose;
	bool notChosen = true;

	system("CLS");

	cout << " Which device would you like to rent?" << endl;
	cout << " 1 - Sony Body" << endl;
	cout << " 2 - Sony " << endl;
	cout << " 3 - Panasonic" << endl;
	cout << " 4 - go back to main menu" << endl;

	while (notChosen) {

		cout << endl;
		cin >> choose;

		switch (choose) {
		case 1:
			if (tab[0].getStock()) {
				int what;
				if (!(cus.Logged())) {
					cout << "You need to log in first. If you don't have an account, you have to register first." << endl;
					cout << "What do you want to do? 1 - Register, 2 - Log in." << endl;

					while (!(cin >> what)) cout << "Incorrect choose! Try again. " << endl;

					if (what == 1) cus.Register();
					else {
						cus.logIn();
						cus.Rent(tab[0]);
					}
				}
				else cus.Rent(tab[0]);
			}
			else cout << "The device cannot be currently rent, because it's out of stock!" << endl;

			notChosen = false;

			break;
		case 2:
			if (tab[1].getStock()) {
				int what;
				if (!(cus.Logged())) {
					cout << "You need to log in first. If you don't have an account, you have to register first." << endl;
					cout << "What do you want to do? 1 - Register, 2 - Log in." << endl;

					while (!(cin >> what)) cout << "Incorrect choose! Try again. " << endl;

					if (what == 1) cus.Register();
					else {
						cus.logIn();
						cus.Rent(tab[1]);
					}
				}
				else cus.Rent(tab[1]);
			}
			else cout << "The device cannot be currently rent, because it's out of stock!" << endl;

			notChosen = false;
		case 3:
			if (tab[2].getStock()) {
				int what;
				if (!(cus.Logged())) {
					cout << "You need to log in first. If you don't have an account, you have to register first." << endl;
					cout << "What do you want to do? 1 - Register, 2 - Log in." << endl;

					while (!(cin >> what)) cout << "Incorrect choose! Try again. " << endl;

					if (what == 1) cus.Register();
					else {
						cus.logIn();
						cus.Rent(tab[2]);
					}
				}
				else cus.Rent(tab[2]);
			}
			else cout << "The device cannot be currently rent, because it's out of stock!" << endl;

			notChosen = false;
		case 4:
			break;
		default:
			cout << "There's no such choice! Try again.";
			break;

		}
	}
}