/* 1.4.	Linked List Problem: Create a singly linked list (not STL) that:
1.	Has functions to insert at start/end/position
2.	Has a function to detect and remove loops
3.	Has a function to find nth node from end
4.	Has a function to reverse list in groups of K nodes
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;  // Initially, list is empty
    }

    // Insert a node at the beginning
    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert a node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;  // If the list is empty, make new node the head
            return;
        }
        Node* temp = head;
        while (temp->next)  // Traverse to the last node
            temp = temp->next;
        temp->next = newNode;  // Add new node at the end
    }

    // Insert a node at a specific position
    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position!\n";
            return;
        }
        if (position == 1) {
            insertAtStart(value);  // Insert at the beginning if position is 1
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; i++) {
            temp = temp->next;  // Traverse to the node just before the position
        }
        if (!temp) {
            cout << "Position out of bounds!\n";
            return;
        }
        newNode->next = temp->next;  // Insert new node at the specified position
        temp->next = newNode;
    }

    // Detect and remove loop in the list
    void detectAndRemoveLoop() {
        Node* slow = head, * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;  // Move fast pointer 2 steps, slow pointer 1 step
            if (slow == fast) {
                cout << "Loop detected! Removing...\n";
                removeLoop(slow);  // Remove loop if detected
                return;
            }
        }
        cout << "No loop detected.\n";
    }

    // Helper function to remove the loop
    void removeLoop(Node* loopNode) {
        Node* ptr1 = head;
        Node* ptr2 = loopNode;
        while (ptr1->next != ptr2->next) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;  // Move both pointers until they meet at the loop entry point
        }
        ptr2->next = nullptr;  // Break the loop by setting the loop node's next to null
    }

    // Find the Nth node from the end of the list
    void findNthFromEnd(int n) {
        Node* first = head;
        Node* second = head;
        for (int i = 0; i < n; i++) {
            if (!first) {
                cout << "N is larger than the list size!\n";
                return;
            }
            first = first->next;  // Move first pointer N steps ahead
        }
        while (first) {
            first = first->next;
            second = second->next;  // Move both pointers one step at a time until first reaches the end
        }
        cout << "The " << n << "th node from the end is: " << second->data << endl;
    }

    // Reverse the list in groups of K nodes
    Node* reverseInGroups(Node* head, int k) {
        if (!head || k <= 1) return head;  // If the list is empty or K is 1, return as is

        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        int count = 0;
        Node* temp = head;
        for (int i = 0; i < k && temp; i++, temp = temp->next) count++;  // Count if there are at least K nodes
        if (count < k) return head;  // If less than K nodes, no reversal

        // Reverse the first K nodes
        count = 0;
        while (current && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        // Recursively reverse the rest of the list
        if (next) head->next = reverseInGroups(next, k);

        return prev;
    }

    // Reverse the list in groups of K nodes (public function)
    void reverseInGroupsK(int k) {
        head = reverseInGroups(head, k);
        cout << "List reversed in groups of " << k << endl;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";  // Print each node's data
            temp = temp->next;
        }
        cout << "NULL\n";  // End of list
    }
};

int main() {
    LinkedList list;
    int choice, value, pos, k;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Start\n2. Insert at End\n3. Insert at Position\n4. Detect & Remove Loop\n5. Find Nth Node from End\n6. Reverse in Groups of K\n7. Display\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtStart(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                list.insertAtPosition(value, pos);
                break;
            case 4:
                list.detectAndRemoveLoop();
                break;
            case 5:
                cout << "Enter N: ";
                cin >> pos;
                list.findNthFromEnd(pos);
                break;
            case 6:
                cout << "Enter K: ";
                cin >> k;
                list.reverseInGroupsK(k);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}

