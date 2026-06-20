// ============================================================
//  Topic   : 1D Arrays - Input and Output
//  Concept : Taking array input from user and printing it
// ============================================================

#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];   // assuming max size 100 (static array)

    // Taking input
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];          // store each value at index i
    }

    // Printing output
    cout << "\nArray elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //  Printing with index info 
    cout << "\nWith index:\n";
    for (int i = 0; i < n; i++) {
        cout << "  arr[" << i << "] = " << arr[i] << "\n";
    }

    // Reverse print
    cout << "\nReverse order: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
 KEY POINTS:
  - Always declare array with max expected size when using static arrays
  - cin >> arr[i]  reads one element at a time
  - Loop from 0 to n-1 for standard traversal
  - Loop from n-1 to 0 for reverse traversal
*/