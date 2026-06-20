// ============================================================
//  Topic   : 1D Arrays - Passing Arrays to Functions
//  Concept : Arrays are ALWAYS passed by reference
//            Changes inside function AFFECT the original array
// ============================================================

#include <iostream>
using namespace std;

// Way 1: Pass as pointer + size
void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Way 2: Pass as array notation (same thing internally)
void doubleElements(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] *= 2;    // modifies the ORIGINAL array (not a copy)
    }
}

// Returning sum from function
int sumArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum;
}

// Returning max from function
int findMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) mx = arr[i];
    }
    return mx;
}

int main() {

    int arr[] = {5, 3, 8, 1, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Modifying via function
    doubleElements(arr, n);
    cout << "After doubling: ";
    printArray(arr, n);

    cout << "Sum: " << sumArray(arr, n) << endl;
    cout << "Max: " << findMax(arr, n)  << endl;

    return 0;
}

/*
 KEY POINTS:
  - int arr[]  and  int* arr  in function parameters are IDENTICAL
  - Arrays are NOT copied when passed to functions — only address is passed
  - This means modifications inside the function change the original
  - To prevent modification, use:  const int arr[]  or  const int* arr
  - sizeof(arr) inside a function returns pointer size (8 bytes), NOT array size
    -> Always pass 'n' separately as a parameter
*/