#include "../include/mainMenu.h"
#include <iostream>
#include <fstream>
using namespace std;

void displayFile() {
	ifstream file("../files/welcome.txt");

	if (file.is_open()) {
		cout << file.rdbuf() << endl;
		file.close();
	}
}