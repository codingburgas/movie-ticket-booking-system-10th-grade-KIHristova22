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

void addMovies() {
    int n;
    for (int i = 0; i < n; i++) {
        string movie;
        cout << "Enter movie name: ";
        getline(cin, movie);
        cout << "Movie added: " << movie << endl;
    }
}

void showMovies() {
    cout << "Available Movies:" << endl;
    cout << "1. Transformers" << endl;
    cout << "2. Harry Potter" << endl;
    cout << "3. Spider-Man" << endl;
    cout << "4. Pirates of the Carribean" << endl;
    cout << "5. Lord of the rings" << endl;
}

void adminMenu()
{
    int choice;
    while (true)
    {
        cout << "1. Add movies" << endl;
        cout << "2. Show movies" << endl;
        cout << "3. Check status" << endl;
        cout << "4. Update status" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            addMovies();
            break;
        }
        case 2:
            showMovies();
            break;
        case 3:
            showStatus();
            break;
        case 4:
            updateStatus();
            break;
        case 5:
            exit(0);
        }
    }
}