// ==========================================================
//  Topic   : Vectors - Sort 0s and 1s
//  Problem : Sort binary array so all 0s come before all 1s
//  Time    : O(n)  |  Space: O(1)
// ==========================================================

#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

// Method 1: Count and Fill O(n) -> Two pass approach
void sort01Count(vector<int>& v) {
    int zeros = 0;
    for (int x : v) if (x == 0) zeros++;   // count 0s

    // fill first 'zeros' positions with 0, rest with 1
    for (int i = 0; i < v.size(); i++) {
        if (i < zeros) v[i] = 0;
        else v[i] = 1;
    }
}

// Method 2: Two Pointer O(n)
// i pointer finds 1s, j pointer finds 0s, swap them
void sort01TwoPointer(vector<int>& v) {
    int i = 0, j = v.size() - 1;

    while (i < j) {
        if( v[i] ==0)  i++;             // skip 0s from left
        if(v[j] == 1) j--;              // skip 1s from right
        if (v[i] ==1 && v[j] == 0) {    // swap 1 and 0
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
}

int main() {

    vector<int> v1 = {1, 0, 1, 0, 0, 1, 1, 0, 1};
    cout << "Original array: ";
    print(v1);

    sort01Count(v1);
    cout << "\nCount and fill: ";
    print(v1);

    vector<int> v2 = {1, 0, 1, 0, 0, 1, 1, 0, 1};
    sort01TwoPointer(v2);
    cout << "Two Pointer: ";
    print(v2);

    return 0;
}

/*
 KEY POINTS:
  - Count & fill is simplest: 2 passes, O(n) time
  - Two pointer: elegant 1-pass, swap 1s and 0s from both ends
  - Both are O(n) time and O(1) space
  - This is a simpler version of the Dutch National Flag problem (0s and 1s only vs 0s, 1s, 2s)
*/