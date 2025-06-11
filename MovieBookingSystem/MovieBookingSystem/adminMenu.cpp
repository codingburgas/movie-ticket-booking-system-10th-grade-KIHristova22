#include "adminMenu.h"
#include <iostream>
#include <fstream>
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

void showStatus() {
    if (a.status == 0) {
        cout << "Occupancy not updated!" << endl;
    }
    else {
        cout << "Occupancy: " << a.status << endl;
    }

    if (a.tickets == 0) {
        cout << "Ticket count not updated!" << endl;
    }
    else {
        cout << "Tickets Sold: " << a.tickets << endl;
    }
}
void updateStatus() {
    cout << "Enter current Occupancy: ";
    cin >> a.status;
    cout << "Enter tickets sold: ";
    cin >> a.tickets;
}

void addfilm() {
    int n;
    ofstream ofile("movies.txt", ios::app);
    cout << "Enter number of films to add: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string movie;
        cout << "Enter movie name: ";
        cin >> ws;
        getline(cin, movie);
        ofile << movie << endl;
    }
    ofile.close();
}