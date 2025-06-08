#pragma once
#include <string>
using namespace std;

class Administration {
private:
    string username;
    string password;

public:
    Administration();
    void authenticate();
};
