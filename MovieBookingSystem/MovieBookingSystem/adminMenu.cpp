#include "adminMenu.h"
#include <iostream>
using namespace std;

Administration a;

Administration::Administration() {
    tickets = 0;
}

void Administration::operator++(int) {
    tickets++;
}

void Administration::increaseTicket() {
    tickets++;
}

void Administration::authenticate() {
    string id, pass;
    cout << "Enter user ID: ";
    cin >> id;
    cout << "Enter password: ";
    cin >> pass;

    try {
        if (id == username && pass == password) {
            cout << "Logged In Successfully!" << endl;
            adminMenu();
        }
        else {
            throw 1;
        }
    }
    catch (int) {
        cout << "Invalid credentials!" << endl;
    }
}