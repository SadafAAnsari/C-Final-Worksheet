/*2.2.	Create a program that:
1.	Reads student records (roll, name, marks) from a text file
2.	Throws an exception if marks are not between 0 and 100
3.	Allows adding new records with proper validation
4.	Saves modified records back to file
*/
// Program to manage student records with marks validation

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdexcept>
using namespace std;

// Custom exception class to handle invalid marks
class InvalidMarksException : public exception {
public:
    const char* what() const throw() {
        return "Marks should be between 0 and 100!";
    }
};

// Structure to hold student details
struct Student {
    int roll;
    string name;
    int marks;
};

// Function to read students from file
vector<Student> readRecords(const string& filename) {
    vector<Student> students;
    ifstream file(filename);

    // If file doesn't exist, create a new empty file
    if (!file) {
        cout << "File not found. Creating a new file..." << endl;
        ofstream newFile(filename);
        newFile.close();
        return students;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Student s;
        ss >> s.roll;
        ss.ignore(); // Skip space
        getline(ss, s.name, ',');
        ss >> s.marks;

        // Check if marks are valid
        if (s.marks < 0 || s.marks > 100) {
            throw InvalidMarksException();
        }

        students.push_back(s);
    }

    file.close();
    return students;
}

// Function to add a new student
void addRecord(vector<Student>& students) {
    Student s;
    cout << "Enter roll number: ";
    cin >> s.roll;
    cin.ignore(); // Ignore leftover newline
    cout << "Enter name: ";
    getline(cin, s.name);
    cout << "Enter marks (0-100): ";
    cin >> s.marks;

    // Check if marks are within valid range
    if (s.marks < 0 || s.marks > 100) {
        throw InvalidMarksException();
    }

    students.push_back(s);
}

// Function to save all students back to file
void saveRecords(const string& filename, const vector<Student>& students) {
    ofstream file(filename);

    if (!file) {
        cout << "Error opening file for saving!" << endl;
        return;
    }

    for (const Student& s : students) {
        file << s.roll << " " << s.name << "," << s.marks << endl;
    }

    file.close();
    cout << "Records saved!" << endl;
}

int main() {
    string filename = "students.txt";
    vector<Student> students;

    try {
        students = readRecords(filename);
    } catch (const exception& e) {
        cout << "Problem reading file: " << e.what() << endl;
        return 1;
    }

    // Show existing student records
    cout << "Student Records:" << endl;
    for (const Student& s : students) {
        cout << s.roll << " " << s.name << " " << s.marks << endl;
    }

    char choice;
    cout << "Do you want to add a new student? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        try {
            addRecord(students);
            saveRecords(filename, students);
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}

