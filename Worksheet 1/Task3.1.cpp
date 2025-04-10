//3.1. Write a program that manages a cinema ticket booking system. The program should display a 5x5 seating arrangement where:
//1.	Available seats are marked with 'O'
//2.	Booked seats are marked with 'X'
//Program should:
//1.	Display the current seating arrangement
//2.	Ask user for row and column number (1-5) for booking
//3.	Mark that seat as booked ('X')
//4.	Show updated seating after each booking
//5.	Display error if user selects already booked seat
//6.	Display error if user enters invalid row/column numbers



#include <iostream>
using namespace std;

int main() {
    char seats[5][5] = {      // Create a 5x5 seating chart, 'O' means seat is open
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'}
    };

    while (true) { // Keep booking seats until user wants to stop
        cout << "Cinema Seats:\n";
        for (int i = 0; i < 5; i++) {  // Show all seats
        for (int j = 0; j < 5; j++) {
        cout << seats[i][j] << " ";
            }
        cout << endl;
        }
        int row, col;
        cout << "Enter row (1-5): ";
        cin >> row;
        cout << "Enter column (1-5): ";
        cin >> col;
        if (row == 0 && col == 0) { // 0 0 means exit
        cout << "Exiting...\n";
        break;
        }
        if (row < 1 || row > 5 || col < 1 || col > 5) { // Check if input is valid
        cout << "Invalid seat! Pick from 1 to 5.\n";
            continue;
        }
        row--; // Change to array index (0-4)
        col--;
        if (seats[row][col] == 'X') { // If seat already booked
        cout << "Seat already booked. Pick another.\n";
        continue;
        }
        seats[row][col] = 'X'; // Book the seat
        cout << "Seat booked!\n";
        char more;
        cout << "Book another seat? (y/n): ";
        cin >> more;
        if (more == 'n' || more == 'N') {
        cout << "Exiting...\n";
        break;
        }
    }
    return 0;
}

