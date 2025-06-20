#include <iostream>
using namespace std;

struct movieDetail {
	int movieNum;
	string name;
	int seat;
	int bookedSeats;

};

movieDetail movies[5];

void initializeMovies() {
	movies[0] = { 1, "Transformers", 100, 0 };
	movies[1] = { 2, "Harry Potter", 100, 0 };
	movies[2] = { 3, "Spider-Man", 100, 0 };
	movies[3] = { 4, "Pirates of the Carribean", 100, 0 };
	movies[4] = { 5, "Lord of the rings", 100, 0 };
}