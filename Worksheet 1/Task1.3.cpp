//1.3.Write a program that reads an array of integer numbers from the user and sorts the numbers in the ascending order.

#include <iostream>
#include <algorithm> // for sort
using namespace std;

int main() {
    int n, arr[100];

    cout << "How many numbers? ";
    cin >> n;
    if (n <= 0 || n > 100) {
        cout << "Invalid number!" << endl;
        return 1;
    }
    cout << "Enter the numbers:" << endl;
    for (int i = 0; i < n; i++) {
    cin >> arr[i];
    }

    sort(arr, arr + n);  //sort() function
    cout << "Numbers in order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
