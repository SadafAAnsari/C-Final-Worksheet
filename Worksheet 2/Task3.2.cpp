/*3.2.Create a program that:
1.	Reads student records (roll, name, marks) from a text file
2.	Throws an exception if marks are not between 0 and 100
3.	Allows adding new records with proper validation
4.	Saves modified records back to file*/


#include <iostream>
#include <fstream>   // for reading and writing files
#include <stdexcept> // for throwing exceptions
#include <string>
#include <vector>    // to store multiple student records
using namespace std;

// Structure to store student information
struct Student {
    int roll;
    string name;
    int marks;
};

// Function to check if marks are valid (0 to 100)
void validateMarks(int marks) {
    if (marks < 0 || marks > 100) {
        throw out_of_range("Marks must be between 0 and 100.");  // Throw error if marks are invalid
    }
}

// Function to read students from a file
vector<Student> readRecords(string fileName) {
    vector<Student> students;
    ifstream inFile(fileName);   // Open file for reading

    if (!inFile) {
        cout << "File not found. A new file will be created later.\n";
        return students;  // Return empty list if file does not exist
    }

    Student student;
    // Read data until end of file
    while (inFile >> student.roll >> student.name >> student.marks) {
        students.push_back(student);  // Add student to the list
    }
    inFile.close();  // Close the file
    return students;
}

// Function to save all student records to a file
void saveRecords(string fileName, vector<Student> students) {
    ofstream outFile(fileName);  // Open file for writing (this will overwrite old content)

    if (!outFile) {
        cout << "Error opening file for saving!\n";
        return;
    }

    for (const auto& student : students) {
        outFile << student.roll << " " << student.name << " " << student.marks << endl;  // Write each student's data
    }
    outFile.close();  // Close the file
}

int main() {
    string fileName = "students.txt";
    vector<Student> students = readRecords(fileName);  // Read old records

    // Show old student records
    if (!students.empty()) {
        cout << "Current Student Records:\n";
        for (const auto& student : students) {
            cout << "Roll: " << student.roll << ", Name: " << student.name << ", Marks: " << student.marks << endl;
        }
    } else {
        cout << "No student records available.\n";
    }

    int choice;
    cout << "\nWhat do you want to do?\n";
    cout << "1. Add a new student\n";
    cout << "2. Update marks of a student\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        // Add a new student
        Student newStudent;
        cout << "Enter Roll Number: ";
        cin >> newStudent.roll;
        cin.ignore();  // Clear the buffer
        cout << "Enter Name: ";
        getline(cin, newStudent.name);
        cout << "Enter Marks: ";
        cin >> newStudent.marks;

        try {
            validateMarks(newStudent.marks);  // Check if marks are valid
            students.push_back(newStudent);   // Add student to the list
            cout << "New student added successfully.\n";
        } catch (const out_of_range& e) {
            cout << "Error: " << e.what() << endl;
        }

    } else if (choice == 2) {
        // Modify marks of an existing student
        int rollNumber;
        cout << "Enter Roll Number to update marks: ";
        cin >> rollNumber;

        bool found = false;
        for (auto& student : students) {
            if (student.roll == rollNumber) {
                found = true;
                cout << "Enter new marks: ";
                int newMarks;
                cin >> newMarks;

                try {
                    validateMarks(newMarks);  // Check if new marks are valid
                    student.marks = newMarks;  // Update marks
    cout << "Marks updated successfully.\n";
    }
     catch (const out_of_range& e) {
    cout << "Error: " << e.what() << endl;
        }
    break;
        }
        }
    if (!found) {
    cout << "Student with Roll Number " << rollNumber << " not found.\n";
        }
    } else {
    cout << "Invalid choice! Please select 1 or 2.\n";
    }
    // Save all records back into the file
    saveRecords(fileName, students);
    return 0;
}

