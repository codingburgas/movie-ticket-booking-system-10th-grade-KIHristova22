#include "../include/mainMenu.h"
#include <iostream>
#include <fstream>
using namespace std;

void displayFile() {
	ifstream file("../files/welcome.txt");

	if (file.is_open()) {
		cout << file.rdbuf() << endl;
		file.close();
	}
}

void mainMenu() {
	int choice;

	while (true) {
		cin >> choice;
	}
	if (cin.fail() || choice < 1 || choice>3) {
		cout << "Invalid input. Please enter a number between 1 and 3." << endl;
		cin.fail();
		cin.ignore();
	}
	else {
		cout << endl;
	}
}