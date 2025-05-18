#include "../include/user.h"

void addUser(User*& head, const string& username, const string& password) {
    User* newUser = new User;
    newUser->username = username;
    newUser->password = password;
    newUser->next = head;
    head = newUser;
}

bool loginUser(User* head, const string& username, const string& password) {
    User* current = head;
    while (current != nullptr) {
        if (current->username == username && current->password == password)
            return true;
        current = current->next;
    }
    return false;
}

void deleteUsers(User*& head) {
    while (head != nullptr) {
        User* temp = head;
        head = head->next;
        delete temp;
    }
}
