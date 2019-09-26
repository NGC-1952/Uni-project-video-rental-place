#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>
#include "Device.h"

using namespace std; 

class Customer{
private:
	string name;
	string surname;
	string town;
	string mail;
	string login;
	string password;
	string codeAddress;
	int homeNumber;
	Device d;

	
public:
	Customer();
	~Customer();

	bool isLogged = false;

	void Register();
	int numberCheck(istream &stream, int* number);
	string letterCheck(string* word);
	string mailCheck(string* mail);
	string codeCheck(string* code);
	string loginCheck(string* login, fstream & f);
	string getPassword();
	bool Logged();
	void logIn();
	void logOut();
	void Rent(Device dev);
};