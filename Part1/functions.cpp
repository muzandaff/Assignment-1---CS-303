#include "functions.h"
#include <iostream>
using namespace std;

// Function to check if a certain integer exists in the array
int checkArray(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i; // Return the index where the value is found
        }
    }
    return -1; // Return -1 if the value is not found
}

// Function to modify a value in the array and return old and new values
void modifyValues(int arr[], int index, int newValue, int &oldValue) {
    oldValue = arr[index]; // Store the old value
    arr[index] = newValue; // Update the array with the new value
}

// Function to add a new value to the end of the array
void addValue(int *&arr, int &size, int newValue) {
    int *newArr = new int[size + 1]; 
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i]; // Copy existing elements to new array
    }
    newArr[size] = newValue; // Add the new value at the end
    delete[] arr; 
    arr = newArr; // Point to the new array
    size++; // Increase the size of the array
}

// Function to set a value to 0 at a specific index (check validity)
void setValueToZero(int arr[], int index, int size) {
    if (index < 0 || index >= size) {
        cout << "Invalid index!" << endl; // Handle invalid index
        return;
    }
    arr[index] = 0; // Set the value at the specified index to 0
}

// Function to display the array
void printArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; // Print each element of the array
    }
    cout << endl;
}
