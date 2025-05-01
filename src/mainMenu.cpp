#include "../include/mainMenu.h"
#include <iostream>
#include <fstream>
using namespace std;

void displayFile() {
	cout << "********************************************" << endl;
	cout << "                 WELCOME                   " << endl;
	cout << "********************************************" << endl;
	cout << "Welcome to the Movie Ticket Booking System!\n"
		"With this console app you can browse movies,\n"
		"check showtimes, pick your seats and book\n"
		"tickets - all from your keyboard. It's fast\n"
		"and easy!" << endl;
	cout << "********************************************" << endl;
	cout << "Choose an option:" << endl;
	cout << "1. Register" << endl;
	cout << "2. Login" << endl;
	cout << "3. Exit" << endl;
	cout << "********************************************" << endl;
}

void mainMenu() {
	int choice;

	while (true) {
		cin >> choice;
	}
	if (cin.fail() || choice < 1 || choice>3) {
		cout << "Invalid input. Please enter a number between 1 and 3." << endl;
		cin.ignore();
	}
	else {
		cout << endl;
	}
}

int main() {
	displayFile();
	mainMenu();
}