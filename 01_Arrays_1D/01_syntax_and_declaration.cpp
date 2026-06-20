// ===============================================================
//  Topic   : 1D Arrays - Syntax and Declaration
//  Concept : How to declare, initialize, and use 1D arrays in C++
// ===============================================================

#include <iostream>
using namespace std;

int main() {

    // WAY 1: Declare and then assign
    int arr1[5];        // declares an array of 5 integers (garbage values inside)
    arr1[0] = 10;
    arr1[1] = 20;
    arr1[2] = 30;
    arr1[3] = 40;
    arr1[4] = 50;

    // WAY 2: Declare + Initialize at the same time
    int arr2[5] = {1, 2, 3, 4, 5};

    // WAY 3: Size auto-decided by compiler 
    int arr3[] = {100, 200, 300};    // compiler sets size = 3

    // WAY 4: Partial initialization (rest become 0)
    int arr4[5] = {7, 8};    // arr4 = {7, 8, 0, 0, 0}

    // WAY 5: All elements set to 0 
    int arr5[5] = {0};    // all five slots become 0

    // Printing arr2
    cout << "arr2 elements: ";
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // Printing arr4
    cout << "arr4 (partial init): ";
    for (int i = 0; i < 5; i++) {
        cout << arr4[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
 KEY POINTS:
  - Array index starts at 0 and ends at (size - 1)
  - Accessing index out of bound causes undefined behavior
  - Array size must be a constant (or use dynamic allocation)
  - Stack-allocated arrays have garbage values if not initialized
*/