/* 2.1.Programming assignments: All questions are mandatory
1.	Write a program with a class Circle having:
1.	Private member: radius (float)
2.	A constructor to initialize radius
3.	A friend function compareTwoCircles that takes two Circle objects and prints which circle has the larger area
 */



#include <iostream>
using namespace std;

class Circle {
private:
    float radius; // To store the radius of the circle
public:
    Circle(float r) { // Constructor to set the radius
        radius = r;
    }
    float getArea() const { // Function to find area of the circle
        return 3.14159 * radius * radius;
    }
    void compareWith(const Circle& other) const { // Function to compare two circles
        float area1 = getArea();
        float area2 = other.getArea();
        cout << "Area of First Circle: " << area1 << endl;
        cout << "Area of Second Circle: " << area2 << endl;
        if (area1 > area2) {
        cout << "First circle is larger.\n";
        } else if (area2 > area1) {
        cout << "Second circle is larger.\n";
        } else {
        cout << "Both circles are equal in area.\n";
        }
    }
};
int main() { // Main program starts here
float r1, r2;
    cout << "Enter radius of first circle: ";
    cin >> r1;
    cout << "Enter radius of second circle: ";
    cin >> r2;
    Circle circle1(r1); // Create first circle
    Circle circle2(r2); // Create second circle
    circle1.compareWith(circle2); // Compare the two circles
    return 0;
}
