//2.1.Create a program that takes a positive integer as input and determines whether it's a "bouncy number". A bouncy number is one where the digits neither consistently increase nor consistently decrease when read from left to right. For example:
// •	123 is NOT bouncy (digits consistently increase)
// •	321 is NOT bouncy (digits consistently decrease)
// •	120 is bouncy (neither consistently increasing nor decreasing)

#include <iostream>
using namespace std;

bool isBouncy(int n) {
    if (n < 100) return false;

    bool up = false, down = false;
    int last = n % 10;
    n /= 10;
    while (n > 0) {
    int curr = n % 10;
    if (curr < last) up = true;  //Checking increasing trend
    if (curr > last) down = true; //decreasing trend
    if (up && down) return true;
    last = curr;
    n /= 10;
    }
return false;
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (isBouncy(n))
    cout << n << " is bouncy." << endl;
    else
    cout << n << " is not bouncy." << endl;
    return 0;
}
