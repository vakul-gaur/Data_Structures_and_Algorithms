// ============================================================
//  Topic   : 1D Arrays - Size and sizeof Operator
//  Concept : How to find the number of elements in an array
// ============================================================

#include <iostream>
using namespace std;

int main() {

    int arr[] = {10, 20, 30, 40, 50};

    // sizeof gives total bytes occupied by the array
    cout << "sizeof(arr) = " << sizeof(arr) << " bytes" << endl;
    // int = 4 bytes, 5 elements -> 5 * 4 = 20 bytes

    cout << "sizeof(arr[0]) = " << sizeof(arr[0]) << " bytes" << endl;
    // size of one int element = 4 bytes

    // Number of elements = total bytes / bytes per element
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Number of elements = " << n << endl;    // 5

    // You can also use sizeof(int) directly
    int n2 = sizeof(arr) / sizeof(int);
    cout << "Using sizeof(int)  = " << n2 << endl;

    // Practical use: no need to hardcode size
    cout << "\nPrinting without hardcoded size:\n";
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Different types
    double darr[] = {1.1, 2.2, 3.3};
    cout << "\ndouble array size in bytes : " << sizeof(darr) << endl;   // 3*8 = 24
    cout << "double array element count : " << sizeof(darr) / sizeof(darr[0]) << endl;

    char carr[] = {'a', 'b', 'c', 'd'};
    cout << "\nchar array size in bytes   : " << sizeof(carr) << endl;   // 4*1 = 4
    cout << "char array element count   : " << sizeof(carr) / sizeof(carr[0]) << endl;

    return 0;
}

/*
 KEY POINTS:
  - sizeof(arr)        -> total bytes of the whole array
  - sizeof(arr[0])     -> bytes of ONE element
  - Length formula     -> sizeof(arr) / sizeof(arr[0])
  - This trick ONLY works inside the same function where array is declared
  - When array is passed to a function, it decays to a pointer -> sizeof gives pointer size (8 bytes on 64-bit)
*/