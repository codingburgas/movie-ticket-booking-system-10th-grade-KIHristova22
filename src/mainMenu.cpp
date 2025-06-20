#include "../include/mainMenu.h"
#include "../include/user.h"
#include "../include/adminMenu.h"
#include <conio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
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
    cout << "3. Admin login" << endl;
	cout << "4. Exit" << endl;
	cout << "********************************************" << endl;
}

void mainMenu() {
    displayMenu();

    User* userHead = nullptr;
    int choice;

    while (true) {
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
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
            a.authenticate();
        }
        else if (choice == 4) {
            cout << "Exiting program. Goodbye!" << endl;
            exit(0);
        }
    }

    deleteUsers(userHead);
}
int main() {
	mainMenu();
}