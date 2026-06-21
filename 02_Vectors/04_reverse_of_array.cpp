// ======================================================
//  Topic   : Vectors - Reverse of Array (In-Place)
//  Concept : Reverse the array without using extra space
//  Time    : O(n)  |  Space: O(1)
// ======================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {

    // Method 1: Two Pointer
    vector<int> v1 = {1, 2, 3, 4, 5};

    int left = 0;
    int right = v1.size() - 1;

    while (left < right) {
        swap(v1[left], v1[right]);
        left++;
        right--;
    }

    cout << "After reverse (Two Pointer): ";
    print(v1);

    // Method 2: STL reverse()
    vector<int> v2 = {10, 20, 30, 40, 50};

    reverse(v2.begin(), v2.end());

    cout << "After STL reverse(): ";
    print(v2);

    return 0;
}

/*
 KEY POINTS:
  - Two pointer swap: most readable, O(n) time, O(1) space
  - STL reverse(begin, end): cleanest one-liner, same complexity
  - Single element and empty -> no swap needed (while condition handles it)
  - Same two-pointer logic works for strings too
*/