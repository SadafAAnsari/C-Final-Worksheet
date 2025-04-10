//1.2 Write a C++ program to implement a number guessing game with different difficulty levels.
//Easy difficulty ranges from 1-8, medium from 1-30, hard from 1-50.Then,generate a random number to check if the guess is correct based on the user's selection.

 #include <iostream>
#include <ctime> // For generating random numbers
using namespace std;

int main() {
    srand(time(0));

    int easy = rand() % 8 + 1;
    int medium = rand() % 30 + 1;
    int hard = rand() % 50 + 1;
    int guess;
    char difficulty;
    cout << " Welcome to the Ultimate Guessing Challenge" << endl;
    cout << "Select a difficulty level:" << endl;
    cout << " (E) Easy   (M) Medium   (H) Hard" << endl;
    cout << "Enter your choice: ";
    cin >> difficulty;

    switch (difficulty) {
        case 'e': case 'E':
            cout << "\nYou chose Easy! Guess a number between 1 and 8: ";
            cin >> guess;
            if (guess == easy) {
                cout << "🎉 Well done! You nailed it!" << endl;
            } else {
                cout << " The correct number was " << easy << "Better luck next time" << endl;
            }
            break;
           case 'm': case 'M':
            cout << "You chose Medium! Guess a number between 1 and 30: ";
            cin >> guess;
            if (guess == medium) {
                cout << " Amazing! You guessed it right!" << endl;
            } else {
                cout << "Not quite! The number was " << medium << "Try again!" << endl;
            }
            break;
           case 'h': case 'H':
            cout << "You chose Hard! Guess a number between 1 and 50: ";
            cin >> guess;
            if (guess == hard) {
                cout << "Incredible! You're a guessing master" << endl;
            } else {
                cout << "No luck! The correct number was " << hard << ". Don't give up" << endl;
            }
            break;
           default:
            cout << "Invalid option! Please restart the game and pick E, M, or H." << endl;
    }
return 0;
}
