#pragma once
#include <string>
using namespace std;

class Administration {
private:
    string username = "admin";
    string password = "admin1";
    int status = 0;

public:
    int tickets;

    Administration();
    void operator++(int);
    void authenticate();
    void increaseTicket();
    friend void showStatus();
    friend void updateStatus();
};

void adminMenu();
void addMovies();
void showMovies();
void showStatus();
void updateStatus();