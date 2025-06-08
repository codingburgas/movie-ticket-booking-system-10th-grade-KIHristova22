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

void Administration::increaseTicket() {
    tickets++;
}

void Administration::showStatus() const {
    if (status == 0) {
        cout << "Occupancy not updated!" << endl;
    }
    else {
        cout << "Occupancy: " << status << endl;
    }

    if (tickets == 0) {
        cout << "Ticket count not updated!" << endl;
    }
    else {
        cout << "Tickets Sold: " << tickets << endl;
    }
}

void Administration::updateStatus() {
    cout << "Enter current Occupancy: ";
    cin >> status;
    cout << "Enter tickets sold: ";
    cin >> tickets;
}