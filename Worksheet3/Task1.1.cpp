/*1.1.	Create a Time class to store hours and minutes. Implement:
1.	Overload the + operator to add two Time objects
2.	Overload the > operator to compare two Time objects
3.	Handle invalid time (>24 hours or >60 minutes) by throwing a custom exception
*/

#include <iostream>
#include <stdexcept>
using namespace std;

class InvalidTimeException : public exception {        // Custom exception class
public:
const char* what() const throw() {
return "Invalid time! Hours must be <= 24 and minutes < 60.";
    }
};
// Time class
class Time {
private:
    int hours, minutes;
    void checkValid() {
    if (hours > 24 || minutes >= 60) {
    throw InvalidTimeException();
        }
    }
public:
    Time(int h = 0, int m = 0) {
    hours = h;
    minutes = m;
        checkValid();
    }

    // Add two Time objects
    Time operator+(const Time& t) {
        int newHours = hours + t.hours;
        int newMinutes = minutes + t.minutes;
        if (newMinutes >= 60) {
            newHours += newMinutes / 60;
            newMinutes %= 60;
        }
        return Time(newHours, newMinutes);
    }

    // Compare two Time objects
    bool operator>(const Time& t) {
        return (hours * 60 + minutes) > (t.hours * 60 + t.minutes);
    }

    void display() {
        cout << hours << " hours " << minutes << " minutes" << endl;
    }
};

int main() {
    try {
    int h1, m1, h2, m2;
    cout << "Enter first time (hours minutes): ";
    cin >> h1 >> m1;
    Time t1(h1, m1);
    cout << "Enter second time (hours minutes): ";
    cin >> h2 >> m2;
    Time t2(h2, m2);
        // Add times
    Time sum = t1 + t2;
    cout << "Sum: ";
    sum.display();

        // Compare times
        if (t1 > t2)
        cout << "First time is greater." << endl;
        else
        cout << "Second time is greater or equal." << endl;

    } catch (const exception& e) {
    cout << "Error: " << e.what() << endl;
    }
    return 0;
}

