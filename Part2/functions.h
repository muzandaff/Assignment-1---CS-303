#include <iostream>
#include <fstream>
using namespace std;

// Function delerations

// A function to check if a certain integer exists in the array if the number is present return the index where the number is present.
int checkArray(int arr[], int size, int value);

// A function that can modify the value of an integer when called with the index of the integer in the array and return the new value and old value back to the user.
void modifyValues(int arr[], int index, int newValue, int &oldValue);

// A function that adds a new integer to the end of the array
void addValue(int *&arr, int &size, int newValue);

// A function which intakes an index of an array and replaces the value with either 0 or removes the integer altogether.
void setValueToZero(int arr[], int index, int size);

// A function that can print the array
void printArray(int arr[], int size);