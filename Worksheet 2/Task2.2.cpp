/*2.2.Create a program with these overloaded functions named findMax:
1.	One that finds maximum between two integers
2.	One that finds maximum between two floating-point numbers
3.	One that finds maximum among three integers
4.	One that finds maximum between an integer and a float */

#include <iostream>
using namespace std;

class MaxFinder {
public:
    int findMax(int a, int b) {
        return (a > b) ? a : b;
    }

    float findMax(float a, float b) {
        return (a > b) ? a : b;
    }

    int findMax(int a, int b, int c) {
        return (a > b && a > c) ? a : (b > c ? b : c);
    }

    float findMax(int a, float b) {
        return (a > b) ? a : b;
    }
};

int main() {
    MaxFinder maxFinder;
    int x, y, z;
    float p, q;

    cout << "Enter two integers: ";
    cin >> x >> y;
    cout << "Max: " << maxFinder.findMax(x, y) << endl;

    cout << "Enter two floats: ";
    cin >> p >> q;
    cout << "Max: " << maxFinder.findMax(p, q) << endl;

    cout << "Enter three integers: ";
    cin >> x >> y >> z;
    cout << "Max: " << maxFinder.findMax(x, y, z) << endl;

    cout << "Enter an integer and a float: ";
    cin >> x >> p;
    cout << "Max: " << maxFinder.findMax(x, p) << endl;

    return 0;
}
