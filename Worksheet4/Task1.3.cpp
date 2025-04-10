/* 1.3.Queue Problem: Implement a queue using arrays (not STL) that:
1.	Has basic enqueue and dequeue operations
2.	Has a function to reverse first K elements
3.	Has a function to interleave first half with second half
4.	Handle queue overflow/underflow
*/

#include <iostream>
using namespace std;

#define MAX_SIZE 10 // Maximum size of queue

class Queue {
private:
    int arr[MAX_SIZE];  // Array to hold queue elements
    int front, rear, size;  // Front, rear indices and size of queue

public:
    // Constructor to initialize queue
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    // Check if queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if queue is full
    bool isFull() {
        return size == MAX_SIZE;
    }

    // Add value to queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot add " << value << endl;
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
        size++;
    }

    // Remove value from queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! No element to remove.\n";
            return -1;
        }
        int removedValue = arr[front];
        front = (front + 1) % MAX_SIZE;
        size--;
        return removedValue;
    }

    // Reverse the first K elements in the queue
    void reverseFirstK(int k) {
        if (k <= 0 || k > size) {
            cout << "Invalid K value.\n";
            return;
        }
        for (int i = 0; i < k / 2; i++) {
            swap(arr[(front + i) % MAX_SIZE], arr[(front + k - 1 - i) % MAX_SIZE]);
        }
        cout << "First " << k << " elements reversed.\n";
    }

    // Interleave the first half with the second half of the queue
    void interleaveQueue() {
        if (size % 2 != 0) {
            cout << "Queue size must be even to interleave.\n";
            return;
        }
        int halfSize = size / 2;
        int temp[MAX_SIZE];

        // Merge first half and second half into temp array
        for (int i = 0; i < halfSize; i++) {
            temp[i * 2] = arr[(front + i) % MAX_SIZE];
            temp[i * 2 + 1] = arr[(front + halfSize + i) % MAX_SIZE];
        }

        // Copy the interleaved result back to the queue
        for (int i = 0; i < size; i++) {
            arr[(front + i) % MAX_SIZE] = temp[i];
        }

        cout << "Queue interleaved successfully.\n";
    }

    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front to rear): ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % MAX_SIZE] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    int choice, value, k;

    // Menu-driven interface for queue operations
    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Reverse First K Elements\n4. Interleave Queue\n5. Display Queue\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value); // Add value to queue
                break;
            case 2:
                value = queue.dequeue(); // Remove value from queue
                if (value != -1) cout << "Dequeued: " << value << endl;
                break;
            case 3:
                cout << "Enter K value: ";
                cin >> k;
                queue.reverseFirstK(k); // Reverse first K elements
                break;
            case 4:
                queue.interleaveQueue(); // Interleave first half with second half
                break;
            case 5:
                queue.display(); // Display queue elements
                break;
            case 6:
                cout << "Exiting program.\n"; // Exit the program
                break;
            default:
                cout << "Invalid choice. Try again.\n"; // Handle invalid choice
        }
    } while (choice != 6); // Continue until user selects exit

    return 0;
}

