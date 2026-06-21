// ========================================================
//  Topic   : Vectors - Basics
//  Concept : Dynamic array that can grow/shrink at runtime
//  Header  : #include <vector>
// ========================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Declaration
    vector<int> v1;                        // empty vector
    vector<int> v2(5);                     // 5 elements, all = 0
    vector<int> v3(5, 10);                 // 5 elements, all = 10
    vector<int> v4 = {1, 2, 3, 4, 5, 6};   // initializer list
    vector<int> v5(v4);                    // copy of v4

    // Size and Capacity
    cout << "v4.size() = " << v4.size() << endl;            // 5 (current elements)
    cout << "v4.capacity() = " << v4.capacity() << endl;    // internal storage (>= size)
    cout << "v1.empty() = " << v1.empty() << endl;          // 1 (true, v1 is empty)

    // Accessing Elements
    cout << "\nv4[0] = " << v4[0] << endl;             // no bounds check (garbage value)
    cout << "v4.at(2) = " << v4.at(2) << endl;         // with bounds check (throws exception)
    cout << "v4.front() = " << v4.front() << endl;     // first element
    cout << "v4.back() = " << v4.back() << endl;       // last element

    // Adding Elements
    v1.push_back(100);
    v1.push_back(200);
    v1.push_back(300);
    cout << "\nAfter push_back: ";
    for (int x : v1) cout << x << " ";
    cout << endl;

    // Removing Elements
    v1.pop_back();          // remove last element
    cout << "After pop_back : ";
    for (int x : v1) cout << x << " ";
    cout << endl;

    // Printing vectors
    cout << "\nv4 = ";
    for (int i = 0; i < v4.size(); i++) cout << v4[i] << " ";
    cout << endl;

    return 0;
}

/*
 KEY POINTS:
  - vector is a dynamic array — size changes at runtime
  - push_back() is amortized O(1) — occasionally doubles capacity
  - at(i) is safer than [i] — throws out_of_range if invalid index
  - size() returns number of elements; capacity() returns allocated storage
*/