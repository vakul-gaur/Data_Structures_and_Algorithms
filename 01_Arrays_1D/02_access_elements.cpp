// ============================================================
//  Topic   : 1D Arrays - Accessing Elements
//  Concept : How to read/write individual elements using index
// ============================================================

#include <iostream>
using namespace std;

int main() {

    int arr[6] = {10, 20, 30, 40, 50, 60};

    // Access by index (0-based)
    cout << "First element (index 0): " << arr[0] << endl;   // 10
    cout << "Third element (index 2): " << arr[2] << endl;   // 30
    cout << "Last element  (index 5): " << arr[5] << endl;   // 60

    // Modifying an element
    arr[2] = 99;   // change 30 -> 99
    cout << "After modification, arr[2] = " << arr[2] << endl;

    // Access using a variable as index
    int idx = 4;
    cout << "Element at index " << idx << " : " << arr[idx] << endl;

    // Loop-based access (most common pattern)
    cout << "\nAll elements via loop: ";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //Range-based for loop
    cout << "Range-based loop     : ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

/*
 KEY POINTS:
  - arr[i]  reads the element at position i
  - arr[i] = val  writes a new value at position i
  - Negative index or index >= size → undefined behavior (no runtime error in C++)
  - Range-based for loop is cleaner but doesn't give you the index
*/