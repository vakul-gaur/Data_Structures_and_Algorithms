// ================================================================
//  Topic   : Vectors - Reverse Part of Array
//  Concept : Reverse only a subarray from index l to r (inclusive)
// ================================================================

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

    // Reverse indices [2..5]
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};

    int l = 2, r = 5;
    while (l < r) {
        swap(v[l], v[r]);
        l++;
        r--;
    }

    cout << "After reversing [2..5]: ";
    print(v);

    // STL Partial Reverse
    vector<int> v2 = {10, 20, 30, 40, 50, 60};

    reverse(v2.begin() + 1, v2.begin() + 4);

    cout << "STL reverse [1..3]: ";
    print(v2);

    // Reverse First Half and Second Half
    vector<int> v3 = {1, 2, 3, 4, 5, 6};

    int n = v3.size();

        reverse(v3.begin(), v3.begin() + n / 2);    // Reverse first half
        reverse(v3.begin() + n / 2, v3.end());      // Reverse second half

    cout << "Both halves reversed: ";
    print(v3);

    return 0;
}

/*
 KEY POINTS:
- Partial reverse reverses elements only between indices l and r.
- Two pointers are used to swap elements from both ends.
- STL syntax: reverse(begin, end).
- reverse(v.begin() + 1, v.begin() + 4) reverses indices [1..3].
- Arrays can be reversed fully or partially.
- Time Complexity: O(k), where k is the number of elements reversed.
- Space Complexity: O(1).
*/