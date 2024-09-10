// main.cpp
#include <iostream>
#include <fstream>
#include <stdexcept> 
#include <limits>     
#include "functions.h"

using namespace std;

int main() {
    // Open input file and verify it opened successfully
    ifstream inputFile("input.txt");
    if (!inputFile) {
        // Error message if unable to open
        cout << "Error: Unable to open file!" << endl;
        return 1; // Return an error code if the file can't be opened
    }

    // Initial array setup
    const int initialCapacity = 10; // Define the initial capacity of the array
    int *arr = new int[initialCapacity]; // Dynamically allocate memory for the array
    int size = 0; // Initialize size of the array
    int capacity = initialCapacity; // Set the current capacity
    int value;// Variable to store values read from the file

    // Reading values from the file and dynamically adding them to the array
    while (inputFile >> value) { // Read integers from the file
        if (size >= capacity) { // Check if the current size exceeds the capacity of the array
            int newCapacity = capacity * 2;  // Double the capacity of the array
            int *newArr = new int[newCapacity];// Allocate a new array with the increased capacity

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
                cin >> valueToCheck; // Function to check if value exists
                int index = checkArray(arr, size, valueToCheck);
                if (index != -1) {
                    cout << "\nValue " << valueToCheck << " found at index " << index << endl;
                } else {
                    cout << "\nValue " << valueToCheck << " not found." << endl;
                }
                break;
            }
            case 2: {
                // Modify value with index and handle exceptions
                int indexToModify, newValue, oldValue;

                // Loop to get valid index
                while (true) {
                    try {
                        cout << "\nEnter index to modify: ";
                        cin >> indexToModify;

                        if (cin.fail()) {
                            throw invalid_argument("Input must be a valid integer!"); // Throw an exception if input is not an integer
                        }
                        if (indexToModify < 0 || indexToModify >= size) {
                            throw out_of_range("Index out of bounds!"); // Throw an exception if index is out of bounds
                        }
                        break; // Valid input, exit loop
                    } catch (const exception &e) {
                        cout << "Error: " << e.what() << endl;
                        cin.clear();  // Clear error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
                    }
                }

                // Loop to get valid new value
                while (true) {
                    try {
                        cout << "\nEnter new value: ";
                        cin >> newValue;

                        if (cin.fail()) {
                            throw invalid_argument("Input must be a valid integer!"); // Throw an exception if input is not an integer
                        }
                        break; // Valid input, exit loop
                    } catch (const exception &e) {
                        cout << "Error: " << e.what() << endl;
                        cin.clear();  // Clear error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
                        // Prompt again inside the loop
                    }
                }



                modifyValues(arr, indexToModify, newValue, oldValue);
                cout << "\nOld value: " << oldValue << "\nNew value: " << arr[indexToModify] << endl;
                break;
            }
            case 3: {
                // Add a new value to the end of the array
                int newValueToAdd;

                // Loop to get valid new value
                while (true) {
                    try {
                        cout << "\nEnter a new value to add to the array: "; 
                        cin >> newValueToAdd;

                        if (cin.fail()) {
                            throw invalid_argument("Input must be a valid integer!"); // Throw an exception if input is not an integer
                        }
                        break; // Valid input, exit loop
                    } catch (const exception &e) {
                        cout << "Error: " << e.what() << endl;
                        cin.clear();  // Clear error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
                    }
                }

                addValue(arr, size, newValueToAdd); // Add the new value to the end of the array
                cout << "\nNew value added: " << newValueToAdd << "\nNew size: " << size << endl;
                break;
            }
            case 4: {
                // Set a value to 0 with an index
                int indexToSetZero;
                cout << "\nEnter index to set to 0: ";
                cin >> indexToSetZero;
                if (indexToSetZero >= 0 && indexToSetZero < size) {
                    setValueToZero(arr, indexToSetZero, size);
                    // Function to set value at index to 0
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
    } while (choice != 0); // Repeat until user chooses to exit// Repeat until user chooses to exit

    // Free dynamically allocated memory
    delete[] arr; // Deallocate memory to prevent memory leaks
    return 0; // Return 0 to indicate successful completion
}
