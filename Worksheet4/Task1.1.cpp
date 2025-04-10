/*1.	STL Container Practice: Write a program using STL containers that:
1.	Uses vector<string> to store names
2.	Uses map<string, int> to store age against each name
3.	Implements functions to:
1.	Add new name-age pair
2.	Find all people above certain age
3.	Sort and display names alphabetically
*/

// Program to store names and ages using vector and map

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// Function to add a new name and age
void addNameAgePair(vector<string>& names, map<string, int>& ageMap, const string& name, int age) {
    names.push_back(name);      // Add name to list
    ageMap[name] = age;         // Add name and age to map
}

// Function to find people older than a given age
void findPeopleAboveAge(const map<string, int>& ageMap, int threshold) {
    cout << "People older than " << threshold << ":\n";
    for (const auto& person : ageMap) {
        if (person.second > threshold) {
            cout << person.first << " (" << person.second << " years old)" << endl;
        }
    }
}

// Function to sort and show names in order
void sortAndDisplayNames(vector<string>& names) {
    vector<string> sortedNames = names; // Copy names
    sort(sortedNames.begin(), sortedNames.end()); // Sort names

    cout << "Names in alphabetical order:\n";
    for (const auto& name : sortedNames) {
        cout << name << endl;
    }
}

int main() {
    vector<string> names;    // List to store names
    map<string, int> ageMap; // Map to store name and age

    int choice;
    do {
        // Show menu
        cout << "\nMenu:\n";
        cout << "1. Add new name and age\n";
        cout << "2. Find people older than a certain age\n";
        cout << "3. Sort and display names\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int age;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            addNameAgePair(names, ageMap, name, age);
            cout << "Added successfully.\n";
        }
        else if (choice == 2) {
            int threshold;
            cout << "Enter age limit: ";
            cin >> threshold;
            findPeopleAboveAge(ageMap, threshold);
        }
        else if (choice == 3) {
            sortAndDisplayNames(names);
        }
        else if (choice == 4) {
            cout << "Goodbye!\n";
        }
        else {
            cout << "Invalid option. Try again.\n";
        }

    } while (choice != 4); // Keep running until user chooses to exit

    return 0;
}

