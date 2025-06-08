#pragma once
#include <string>
using namespace std;

class Admin {
private:
	string id;
	string pass;

public:
	int tickets;
	int status;

	Admin();
	void increaseTicket();
	void adminLog();
	friend void showStatus();
	friend void updateStatus();
};

void adminMenu();
void addFilm();
void showFilm();
void showStatus();
void updateStatus();