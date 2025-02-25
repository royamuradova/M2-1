#include <iostream>

using namespace std;

// Function to reverse an array and return a pointer to the new array
int* reverseArray(const int* arr, int size) {
    int* reversedArr = new int[size]; // Dynamically allocate memory for the new array
    for (int i = 0; i < size; i++) {
        reversedArr[i] = arr[size - 1 - i]; // Copy elements in reverse order
    }
    return reversedArr; // Return pointer to the new array
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Sample array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate array size

    int* reversedArr = reverseArray(arr, size); // Call function

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << reversedArr[i] << " ";
    }
    cout << endl;

    delete[] reversedArr; // Free allocated memory

    return 0;
}
