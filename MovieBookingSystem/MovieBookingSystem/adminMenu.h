#pragma once
#include <string>
using namespace std;

class Administration {
private:
    string username;
    string password;
    int status;

public:
    int tickets;

    Administration();
    void authenticate();
    void increaseTicket();
    void showStatus() const;
    void updateStatus();
};