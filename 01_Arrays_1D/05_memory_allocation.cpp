// ============================================================
//  Topic   : 1D Arrays - Memory Allocation
//  Concept : Stack allocation
// ============================================================

#include <iostream>
using namespace std;

int main() {

    // STACK ALLOCATION (static)
    int stack_arr[5] = {10, 20, 30, 40, 50};

    // Array elements are stored CONTIGUOUSLY in memory
    cout << "Stack Array Memory Addresses" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] = " << stack_arr[i]
             << "  | address = " << &stack_arr[i] << endl;
    }

    // Array name is a pointer to first element
    cout << "\nstack_arr        = " << stack_arr << endl;        // Each address differs by 4 (size of int)
    cout << "&stack_arr[0]    = " << &stack_arr[0] << endl;      // Both print the same address!

    return 0;
}

/*
 KEY POINTS:
  - Stack array: fixed size known at compile time, auto-freed when scope ends
  - Elements are stored contiguously → address increases by sizeof(type) each step
  - Array name = address of first element (pointer to array)
*/