//1.1 Write a program that takes a temperature value from the user. It should then allow the user to choose between Celsius (C) and Fahrenheit (F) for conversion. After the user selection, it should then convert the entered temperature to the chosen scale and display the result.
//Use appropriate data types for temperature and handle error like non-numeric input.
//Use the following formula for conversion:
//F = (C x 9/5) + 32
//C = (F - 32) x 5/9
#include <iostream>
using namespace std;

int main() {
    double temp;
    char choice;
    cout << "Enter the temperature: ";
    cin >> temp;
    cout << "Convert to Celsius (C) or Fahrenheit (F)? ";
    cin >> choice;

    if (choice == 'C' || choice == 'c') {
        double celsius = (temp - 32) * 5.0 / 9.0;
        cout << "Temperature in Celsius: " << celsius << "°C" << endl;
    }
    else if (choice == 'F' || choice == 'f') {
        double fahrenheit = (temp * 9.0 / 5.0) + 32;
        cout << "Temperature in Fahrenheit: " << fahrenheit << "°F" << endl;
    }
    else {
        cout << "Invalid choice! Please enter 'C' or 'F'." << endl;
    }

    return 0;
}


