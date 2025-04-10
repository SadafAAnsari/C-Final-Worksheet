//3.1.Write a program that reads the titles of 10 books (use an array of 150 characters) and writes them in a binary file selected by the user. The program should read a title and display a message to indicate if it is contained in the file or not.

#include <iostream>
#include <fstream>  // For file operations
#include <cstring>  // For using strcmp
using namespace std;

int main() {
    char bookTitles[10][150];  // Array to store 10 book titles (each up to 150 characters)
    ofstream outFile;          // Output file stream to write into a file

    // Open a binary file in append mode (creates file if it doesn't exist)
    outFile.open("bookTitles.dat", ios::binary | ios::app);
    if (!outFile) {
    cout << "Error: Could not open file for writing!" << endl;
    return 1; // Exit if file can't be opened
    }

    // Take 10 book titles from the user
    cout << "Enter titles of 10 books:" << endl;
    cin.ignore(); // Clear the input buffer before taking input

    for (int i = 0; i < 10; i++) {
        cout << "Book " << i + 1 << ": ";
        cin.getline(bookTitles[i], 150); // Read the whole line as title
        outFile.write(bookTitles[i], sizeof(bookTitles[i])); // Save the title to the file
    }

    outFile.close(); // Close the file after writing all titles

    // Now ask the user for a title to search
    char searchTitle[150];
    cout << "\nEnter a book title to search: ";
    cin.getline(searchTitle, 150); // Take the title to search
    ifstream inFile("bookTitles.dat", ios::binary); // Open the file for reading
    if (!inFile) {
    cout << "Error: Could not open file for reading!" << endl;
    return 1; // Exit if file can't be opened
    }
    bool found = false; // To keep track if title is found
    char title[150];    // Temporary array to hold titles from file
    // Read titles one by one and compare
    while (inFile.read(title, sizeof(title))) {
    if (strcmp(title, searchTitle) == 0) { // Compare the searched title with file title
    found = true;
    break; // No need to search further
        }
    }
    inFile.close(); // Always close the file after reading
    // Show result
    if (found) {
    cout << "Title found in the file!" << endl;
    } else {
    cout << "Title not found in the file." << endl;
    }

    return 0; // End of program
}
