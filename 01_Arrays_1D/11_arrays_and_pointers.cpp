// ============================================================
//  Topic   : 1D Arrays - Arrays and Pointers
//  Concept : The connection between arrays and pointers in C++
// ============================================================

#include <iostream>
using namespace std;

int main() {

    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;

    // Array name is a pointer to first element
    cout << "arr= " << arr << endl;              // address of arr[0]
    cout << "&arr[0]= " << &arr[0] << endl;      // same address
    cout << "*arr= " << *arr << endl;            // value at arr[0] = 10
    cout << "arr[0]= " << arr[0] << endl;        // same as *arr

    cout << endl;

    // Pointer arithmetic: arr + i moves i positions forward (by sizeof(int) bytes)
    cout << "*(arr + 0)= " << *(arr + 0) << endl;    // arr[0] = 10
    cout << "*(arr + 1)= " << *(arr + 1) << endl;    // arr[1] = 20
    cout << "*(arr + 4)= " << *(arr + 4) << endl;    // arr[4] = 50

    // arr[i]  is exactly the same as  *(arr + i)
    // This is how the compiler actually handles indexing internally

    cout << endl;

    // Using a separate pointer to traverse the array
    int* ptr = arr;     // ptr now points to arr[0]

    cout << "Traversal using pointer:\n";
    for (int i = 0; i < n; i++) {
        cout << "  ptr[" << i << "] = " << ptr[i]
             << "  | *(ptr+" << i << ") = " << *(ptr + i) << endl;
    }

    // Incrementing the pointer 
    cout << "\nUsing ptr++ to walk through:\n";
    ptr = arr;          // reset pointer to start
    for (int i = 0; i < n; i++) {
        cout << *ptr << " ";
        ptr++;          // move to next element
    }
    cout << endl;

    // Modifying array through pointer
    ptr = arr;
    *ptr = 99;          // modifies arr[0]
    *(ptr + 2) = 77;    // modifies arr[2]

    cout << "\nAfter pointer modification: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    // Difference: array name vs pointer
    // arr = arr + 1;   // ERROR: array name is a constant pointer, can't reassign
    // ptr = ptr + 1;   // OK: ptr is a regular pointer, can be moved

    return 0;
}

/*
 KEY POINTS:
  - arr (array name) = constant pointer to first element = &arr[0]
  - arr[i]  ==  *(arr + i)  (these are equivalent)
  - Pointer arithmetic: ptr + 1 moves forward by sizeof(type) bytes, not 1 byte
  - Array name is a CONST pointer -> can't do arr++ or arr = something
  - A separate int* ptr = arr is movable (ptr++ is valid)
  - This is why arrays are passed as pointers to functions (they decay to pointer)
*/