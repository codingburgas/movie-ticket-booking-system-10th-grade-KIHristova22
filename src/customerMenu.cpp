#include <iostream>
using namespace std;

struct movieDetail {
	int movieNum;
	string name;
	int seat;
	int bookedSeats;
    bool seats[10][10];
};

movieDetail movies[5];

void initializeMovies() {
	movies[0] = { 1, "Transformers", 100, 0 };
	movies[1] = { 2, "Harry Potter", 100, 0 };
	movies[2] = { 3, "Spider-Man", 100, 0 };
	movies[3] = { 4, "Pirates of the Carribean", 100, 0 };
	movies[4] = { 5, "Lord of the rings", 100, 0 };

    for (int m = 0; m < 5; ++m) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                movies[m].seats[i][j] = false;
            }
        }
    }
}

void displaySeats(const movieDetail& movie) {
    cout << "Seat layout (O = available, X = booked):" << endl;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (movie.seats[i][j]) {
                cout << "X ";
            }
            else {
                cout << "O ";
            }
        }
        cout << "  Row " << i + 1 << endl;
    }
}

void viewMovies() {
	cout << "Available Movies:" << endl;
	for (int i = 0; i < 5; ++i) {
		cout << movies[i].movieNum << ". " << movies[i].name
			<< " - Available Seats: " << movies[i].seat
			<< ", Booked: " << movies[i].bookedSeats << endl;
	}
}

void bookTickets() {
    int choice, tickets;
    viewMovies();
    cout << "Enter the movie number to book tickets for: ";
    cin >> choice;

    if (choice < 1 || choice > 5) {
        cout << "Invalid movie number!" << endl;
        return;
    }

    movieDetail& movie = movies[choice - 1];
    displaySeats(movie);

    cout << "How many tickets would you like to book for " << movie.name << "? ";
    cin >> tickets;

    if (tickets <= 0 || tickets > movie.seat) {
        cout << "Invalid number of tickets!" << endl;
        return;
    }

    for (int i = 0; i < tickets; ++i) {
        int row, col;
        cout << "Select seat " << i + 1 << " (row [1-10] and column [1-10]): ";
        cin >> row >> col;

        row--; col--;

        if (row < 0 || row >= 10 || col < 0 || col >= 10) {
            cout << "Invalid seat position!" << endl;
            i--; 
            continue;
        }

        if (movie.seats[row][col]) {
            cout << "Seat already booked! Choose a different seat.\n";
            i--; 
        }
        else {
            movie.seats[row][col] = true;
            movie.seat--;
            movie.bookedSeats++;
        }
    }

    cout << "Tickets booked successfully for " << movie.name << "!" << endl;
}

void cancelTickets() {
    int choice, tickets;
    viewMovies();
    cout << "Enter the movie number to cancel tickets for: ";
    cin >> choice;

    if (choice < 1 || choice > 5) {
        cout << "Invalid movie number!" << endl;
        return;
    }

    movieDetail& movie = movies[choice - 1];
    displaySeats(movie);

    cout << "How many tickets would you like to cancel for " << movie.name << "? ";
    cin >> tickets;

    if (tickets <= 0 || tickets > movie.bookedSeats) {
        cout << "Invalid number of tickets!" << endl;
        return;
    }

    for (int i = 0; i < tickets; ++i) {
        int row, col;
        cout << "Enter seat " << i + 1 << " to cancel (row [1-10] and column [1-10]): ";
        cin >> row >> col;

        row--; col--;

        if (row < 0 || row >= 10 || col < 0 || col >= 10) {
            cout << "Invalid seat position!" << endl;
            i--; 
            continue;
        }

        if (!movie.seats[row][col]) {
            cout << "That seat is not booked! Try again.\n";
            i--; 
        }
        else {
            movie.seats[row][col] = false;
            movie.seat++;
            movie.bookedSeats--;
        }
    }

    cout << "Tickets cancelled successfully for " << movie.name << "!" << endl;
}

void customerMenu() {
    initializeMovies();
    int choice;

    while (true) {
        cout << "1. View Movies" << endl;
        cout << "2. Book Tickets" << endl;
        cout << "3. Cancel Tickets" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            viewMovies();
            break;
        case 2:
            bookTickets();
            break;
        case 3:
            cancelTickets();
            break;
        case 4:
            cout << "Exiting customer menu." << endl;
            return;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}