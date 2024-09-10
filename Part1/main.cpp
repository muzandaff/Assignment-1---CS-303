#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;

int main() {
    // Open input file and verify it opened successfully
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "Error: Unable to open file!" << endl;
        return 1; // Return an error code if the file can't be opened
    }

        // Initial array setup
        const int initialCapacity = 10; // Define the initial capacity of the array
        int *arr = new int[initialCapacity]; // Dynamically allocate memory for the array
        int size = 0; // Initialize size of the array
        int capacity = initialCapacity; // Set the current capacity
        int value; // Variable to store values read from the file

        // Reading values from the file and dynamically adding them to the array
        while (inputFile >> value) { // Read integers from the file
            // Check if the current size exceeds the capacity of the array
            if (size >= capacity) {
                // Double the capacity of the array
                int newCapacity = capacity * 2;
                int *newArr = new int[newCapacity]; // Allocate a new array with the increased capacity

                // Copy existing values to the new array
                for (int i = 0; i < size; i++) {
                    newArr[i] = arr[i];
                }
                delete[] arr;
                arr = newArr;
                capacity = newCapacity;
            }
            arr[size++] = value;
        }
        inputFile.close(); // Close the input file after reading

    // Menu printing
    int choice; 
    do {
        cout << "\nMenu: \n";
        cout << "1. Check value existence\n";
        cout << "2. Modify value w/ index\n";
        cout << "3. Add a new value to end of array\n";
        cout << "4. Set a value to 0 w/ index\n";
        cout << "5. Display the array\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Get user's choice

        switch (choice) {
            case 1: {
                // Check existence of value in array
                int valueToCheck;
                cout << "\nEnter a number to check in the array: ";
                cin >> valueToCheck;
                int index = checkArray(arr, size, valueToCheck); // Function to check if value exists
                if (index != -1) {
                    cout << "\nValue " << valueToCheck << " found at index " << index << endl;
                } else {
                    cout << "\nValue " << valueToCheck << " not found." << endl;
                }
                break;
            }
            case 2: {
                // Modify the value at a specific index
                int indexToModify, newValue, oldValue;
                cout << "\nEnter index to modify: ";
                cin >> indexToModify;
                if (indexToModify >= 0 && indexToModify < size) {
                    cout << "Enter new value: ";
                    cin >> newValue;
                    modifyValues(arr, indexToModify, newValue, oldValue); // Function to modify value at index
                    cout << "\nOld value: " << oldValue << "\nNew value: " << arr[indexToModify] << endl;
                } else {
                    cout << "\nInvalid index!" << endl; // Handle invalid index
                }
                break;
            }
            case 3: {
                // Add a new value to the end of the array
                int newValueToAdd;
                cout << "\nEnter a new value to add to the array: ";
                cin >> newValueToAdd;
                addValue(arr, size, newValueToAdd); // Function to add value to the array
                cout << "\nNew value added: " << newValueToAdd << "\nNew size: " << size << endl;
                break;
            }
            case 4: {
                // Set a value to 0 with an index
                int indexToSetZero;
                cout << "\nEnter index to set to 0: ";
                cin >> indexToSetZero;
                if (indexToSetZero >= 0 && indexToSetZero < size) {
                    setValueToZero(arr, indexToSetZero, size); // Function to set value at index to 0
                    cout << "\nValue at index " << indexToSetZero << " set to 0." << endl;
                } else {
                    cout << "\nInvalid index!" << endl; // Handle invalid index
                }
                break;
            }
            case 5: {
                // Display array (added for clarity)
                cout << "\n";
                printArray(arr, size); // Function to print the array
                break;
            }
            case 0: {
                // Exit program
                cout << "\nExiting program..." << endl;
                break;
            }
            default: {
                // Handle invalid menu choice
                cout << "\nInvalid choice. Please try again." << endl;
            }
        }
    } while (choice != 0); // Repeat until user chooses to exit

    // Free dynamically allocated memory
    delete[] arr; // Deallocate memory to prevent memory leaks
    return 0; // Return 0 to indicate successful completion
}
