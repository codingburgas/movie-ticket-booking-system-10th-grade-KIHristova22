#include "../include/user.h"
#include <iostream>
#include <fstream>

//Adds a new user to the beginning of the linked list
void addUser(User*& head, const string& username, const string& password) {
    User* newUser = new User;
    newUser->username = username;
    newUser->password = password;
    newUser->next = head;
    head = newUser; // Update head to point to the new user
}

//Checks if a user with the given username and password exists
bool loginUser(User* head, const string& username, const string& password) {
    User* current = head; // Start from the head of the list
    while (current != nullptr) {
        if (current->username == username && current->password == password)
            return true;
        current = current->next;
    }
    return false;
}
//Frees memory by deleting all users in the linked list
void deleteUsers(User*& head) {
    while (head != nullptr) {
        User* temp = head;
        head = head->next;
        delete temp;
    }
}

//Saves all users to "users.txt"
void saveUsers(User* head) {
    ofstream fout("users.txt");
    if (!fout.is_open()) {
        cout << "Error opening file to save users." << endl;
        return;
    }

    User* temp = head;
    while (temp) {
        fout << temp->username << ' ' << temp->password << endl;
        temp = temp->next;
    }
    fout.close();
}