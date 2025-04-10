//Task 1: Basic student grading system prototype using classes and objects. [20 Marks]
//Write a program that manages a simple student grade calculator with the following requirements. Create a Student class that has:
//1.	Student name (string)
//2.	Three subject marks (integers)
//3.	A basic member function to calculate average
//The program should:
//1.	Accept student details (name and marks) from user input
//2.	Calculate and display:
//1.	Total marks
//2.	Average marks
//3.	Grade (A for ≥90%, B for ≥80%, C for ≥70%, D for ≥60%, F for <60%)
//4.	Display a message if any mark is below 0 or above 100

#include <iostream>
using namespace std;

class Student { // Class to handle student info and grades
    string name; // Store student's name
    int marks[3]; // Store marks for 3 subjects

public:
    void getDetails() { // Ask user for name and marks
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter marks for 3 subjects: ";
        for (int i = 0; i < 3; i++) {
        cin >> marks[i];
        if (marks[i] < 0 || marks[i] > 100) { // Check if marks are valid
        cout << "Marks must be between 0 and 100!\n";
        return;
        }
        }
    }
    int calculateTotal() { // Add up all the marks
        return marks[0] + marks[1] + marks[2];
    }
    float calculateAverage() { // Find the average
        return calculateTotal() / 3.0;
    }
    char calculateGrade() { // Give grade based on average
        float avg = calculateAverage();
        if (avg >= 90) return 'A';
        else if (avg >= 80) return 'B';
        else if (avg >= 70) return 'C';
        else if (avg >= 60) return 'D';
        else return 'F';
    }
    void displayResults() { // Show all details
        cout << "\nStudent Name: " << name << endl;
        cout << "Total Marks: " << calculateTotal() << endl;
        cout << "Average Marks: " << calculateAverage() << endl;
        cout << "Grade: " << calculateGrade() << endl;
    }
};
int main() { // Program starts here
    Student student; // Create a student
    student.getDetails(); // Input details
    student.displayResults(); // Show results
    return 0;
}
