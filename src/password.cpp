#include <iostream>
#include <string>
#include "conio.h" //For _getch()
using namespace std;

//Function to get hidden password input from user
string hidePass() {
    string password;
    char ch;
    //Read characters until Enter is pressed
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