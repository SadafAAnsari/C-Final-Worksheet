/* 2.1.Create a base class Vehicle and two derived classes Car and Bike:
1.	Vehicle has registration number and color
2.	Car adds number of seats
3.	Bike adds engine capacity
4.	Each class should have its own method to write its details to a file
5.	Include proper inheritance and method overriding
*/

#include <iostream>
#include <fstream>
using namespace std;

// Base class: Vehicle (stores common info)
class Vehicle {
protected:
    string registrationNumber;
    string color;
public:
    Vehicle(string regNum, string clr) : registrationNumber(regNum), color(clr) {}

    // Virtual function to save vehicle details in a file
    virtual void writeToFile(ofstream& file) const {
        file << "Vehicle - Reg No: " << registrationNumber << ", Color: " << color << endl;
    }

    // Virtual function to show vehicle details
    virtual void display() const {
        cout << "Vehicle - Reg No: " << registrationNumber << ", Color: " << color << endl;
    }
};

// Derived class: Car (adds seats info)
class Car : public Vehicle {
private:
    int numberOfSeats;
public:
    Car(string regNum, string clr, int seats) : Vehicle(regNum, clr), numberOfSeats(seats) {}

    // Override: Save car details
    void writeToFile(ofstream& file) const override {
        file << "Car - Reg No: " << registrationNumber << ", Color: " << color << ", Seats: " << numberOfSeats << endl;
    }

    // Override: Show car details
    void display() const override {
        cout << "Car - Reg No: " << registrationNumber << ", Color: " << color << ", Seats: " << numberOfSeats << endl;
    }
};

// Derived class: Bike (adds engine capacity info)
class Bike : public Vehicle {
private:
    int engineCapacity;
public:
    Bike(string regNum, string clr, int engineCap) : Vehicle(regNum, clr), engineCapacity(engineCap) {}

    // Override: Save bike details
    void writeToFile(ofstream& file) const override {
        file << "Bike - Reg No: " << registrationNumber << ", Color: " << color << ", Engine: " << engineCapacity << "cc" << endl;
    }

    // Override: Show bike details
    void display() const override {
        cout << "Bike - Reg No: " << registrationNumber << ", Color: " << color << ", Engine: " << engineCapacity << "cc" << endl;
    }
};

int main() {
    string regNum, color;
    int choice, seats, engineCap;

    // Open file to store vehicle details
    ofstream file("vehicles.txt", ios::app); // app mode means add at the end
    if (!file) {
        cout << "File couldn't be opened!" << endl;
        return 1;
    }

    // User chooses the type of vehicle
    cout << "Choose Vehicle Type:\n1. Car\n2. Bike\nEnter choice: ";
    cin >> choice;
    cin.ignore(); // Clear buffer for getline

    // Get common input
    cout << "Enter Registration Number: ";
    getline(cin, regNum);
    cout << "Enter Color: ";
    getline(cin, color);

    // Handle Car
    if (choice == 1) {
        cout << "Enter Number of Seats: ";
        cin >> seats;
        Car car(regNum, color, seats);
        car.writeToFile(file);
        cout << "Car details saved successfully!\n";
        car.display();
    }
    // Handle Bike
    else if (choice == 2) {
        cout << "Enter Engine Capacity (in CC): ";
        cin >> engineCap;
        Bike bike(regNum, color, engineCap);
        bike.writeToFile(file);
        cout << "Bike details saved successfully!\n";
        bike.display();
    }
    // Invalid choice
    else {
        cout << "Invalid choice entered!" << endl;
    }

    file.close(); // Close the file
    return 0;
}

