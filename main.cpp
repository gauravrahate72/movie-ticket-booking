#include <iostream>
#include <vector>

using namespace std;

class Movie {
public:
    string name;
    vector<string> showtimes;
    int ticketPrice;

    Movie(string movieName, int price) {
        name = movieName;
        ticketPrice = price;
    }

    void addShowtime(string time) {
        showtimes.push_back(time);
    }
};

class Theater {
public:
    string name;
    vector<vector<bool>> seatAvailability;

    Theater(string theaterName, int rows, int cols) {
        name = theaterName;
        seatAvailability.resize(rows, vector<bool>(cols, true));
    }

    bool bookSeats(int row, int col) {
        if (row >= 0 && row < seatAvailability.size() && col >= 0 && col < seatAvailability[0].size()) {
            if (seatAvailability[row][col]) {
                seatAvailability[row][col] = false;
                return true;
            }
        }
        return false;
    }

    void displaySeating() {
        cout << "Seating Arrangement:" << endl;
        for (int i = 0; i < seatAvailability.size(); ++i) {
            for (int j = 0; j < seatAvailability[0].size(); ++j) {
                if (seatAvailability[i][j]) {
                    cout << "O ";
                } else {
                    cout << "X ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    // Sample data
    vector<Movie> movies;
    movies.push_back(Movie("Avengers: Endgame", 15));
    movies.push_back(Movie("Inception", 12));

    Theater theater("Super Cinema", 5, 7);
    // Assuming a theater with 5 rows and 7 columns for seats.

    cout << "Welcome to Super Cinema!" << endl;

    // Display movie listings and showtimes to the user.
    cout << "Movies Available:" << endl;
    for (int i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ". " << movies[i].name << " - Ticket Price: $" << movies[i].ticketPrice << endl;
        cout << "   Showtimes: ";
        for (const string& time : movies[i].showtimes) {
            cout << time << " | ";
        }
        cout << endl;
    }

    // Prompt user to select a movie and showtime.
    int movieChoice, showtimeChoice;
    cout << "Select a movie (Enter the corresponding number): ";
    cin >> movieChoice;
    if (movieChoice < 1 || movieChoice > movies.size()) {
        cout << "Invalid choice. Exiting..." << endl;
        return 1;
    }
    movieChoice--; // Convert to zero-based index

    cout << "Select a showtime (Enter the corresponding number): ";
    cin >> showtimeChoice;
    if (showtimeChoice < 1 || showtimeChoice > movies[movieChoice].showtimes.size()) {
        cout << "Invalid choice. Exiting..." << endl;
        return 1;
    }
    showtimeChoice--; // Convert to zero-based index

    cout << "You have selected: " << movies[movieChoice].name << " at " << movies[movieChoice].showtimes[showtimeChoice] << endl;

    // Display the seating arrangement and let the user choose seats.
    cout << "Please select your seats (row and column numbers separated by a space): ";
    int selectedRow, selectedCol;
    cin >> selectedRow >> selectedCol;

    if (!theater.bookSeats(selectedRow - 1, selectedCol - 1)) {
        cout << "Invalid seat selection or the seat is already booked. Exiting..." << endl;
        return 1;
    }

    // Book the selected seats and calculate the total cost.
    int numTickets;
    cout << "Enter the number of tickets you want to purchase: ";
    cin >> numTickets;
    int totalCost = numTickets * movies[movieChoice].ticketPrice;

    // Confirm the booking and display the details to the user.
    cout << "Booking confirmed!" << endl;
    cout << "Movie: " << movies[movieChoice].name << endl;
    cout << "Showtime: " << movies[movieChoice].showtimes[showtimeChoice] << endl;
    cout << "Seats: Row " << selectedRow << ", Column " << selectedCol << " - " << numTickets << " tickets" << endl;
    cout << "Total Cost: $" << totalCost << endl;

    return 0;
}