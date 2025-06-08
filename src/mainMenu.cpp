#include "../include/mainMenu.h"
#include "../include/user.h"
#include "../src/adminMenu.h"
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;

string hidePass() {
    string password;
    char ch;
    while ((ch = _getch()) != '\r') { 
        if (ch == '\b') { 
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        }
        else {
            password += ch;
            cout << '*';
        }
    }
    cout << endl;
    return password;
}

void displayMenu() {
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
    displayMenu();

    User* userHead = nullptr;
    int choice;

    while (true) {
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            continue;
        }

        if (choice == 1) {
            string username;
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            string password = hidePass();
            addUser(userHead, username, password);
            cout << "Registration successful!" << endl;
        }
        else if (choice == 2) {
            string username;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            string password = hidePass();
            if (loginUser(userHead, username, password)) {
                cout << "Login successful! Welcome, " << username << "!" << endl;
            }
            else {
                cout << "Login failed. Please check your credentials." << endl;
            }
        }
        else if (choice == 3) {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
    }

    deleteUsers(userHead);
}
int main() {
	mainMenu();
}