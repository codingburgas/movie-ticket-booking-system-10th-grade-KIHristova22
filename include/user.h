#pragma once
#include <string>
using namespace std;

struct User {
    string username;
    string password;
    User* next;
};

void addUser(User*& head, const string& username, const string& password);
bool loginUser(User* head, const string& username, const string& password);
void deleteUsers(User*& head);