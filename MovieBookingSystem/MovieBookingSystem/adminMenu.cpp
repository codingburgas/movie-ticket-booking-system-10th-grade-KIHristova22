#include "adminMenu.h"
#include <iostream>
using namespace std;

Administration::Administration() {
    username = "admin1";
    password = "adminpassword";
}

void Administration::authenticate() {
    string id;
    string pass;

    cout << "Enter user ID: ";
    cin >> id;

    cout << "Enter password: ";
    cin >> pass;

    if (id == username && pass == password) {
        cout << "Logged in successfully!" << endl;
    }
    else {
        cout << "Invalid credentials." << endl;
    }
}