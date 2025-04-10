/* 1.2.	Stack Problem: Implement a stack using arrays (not STL) that:
1.	Has basic push and pop operations
2.	Has a function to find middle element
3.	Has a function to reverse only bottom half of stack
4.	Maintain stack size of 10
*/

#include <iostream>
using namespace std;

#define MAX_SIZE 10 // Max size of stack

class Stack {
private:
    int arr[MAX_SIZE]; // Array to store stack items
    int top;           // Top index of stack
public:
    Stack() {
        top = -1; // Stack starts empty
    }

    // Add value to stack
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack full! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }

    // Remove value from top of stack
    int pop() {
        if (top < 0) {
            cout << "Stack empty! Cannot pop.\n";
            return -1;
        }
        return arr[top--];
    }

    // Show middle value of stack
    void findMiddle() {
        if (top < 0) {
            cout << "Stack is empty!\n";
            return;
        }
        int middleIndex = top / 2;
        cout << "Middle element: " << arr[middleIndex] << endl;
    }

    // Reverse only the bottom half of the stack
    void reverseBottomHalf() {
        if (top < 1) {
            cout << "Not enough items to reverse bottom half.\n";
            return;
        }
        int halfSize = (top + 1) / 2;
        for (int i = 0; i < halfSize / 2; i++) {
            swap(arr[i], arr[halfSize - 1 - i]);
        }
        cout << "Bottom half reversed.\n";
    }

    // Show all elements of stack
    void display() {
        if (top < 0) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    int choice, value;
    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n2. Pop\n3. Find Middle\n4. Reverse Bottom Half\n5. Display Stack\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                value = stack.pop();
                if (value != -1)
                    cout << "Popped: " << value << endl;
                break;
            case 3:
                stack.findMiddle();
                break;
            case 4:
                stack.reverseBottomHalf();
                break;
            case 5:
                stack.display();
                break;
            case 6:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Wrong option. Try again.\n";
        }
    } while (choice != 6);
    return 0;
}

