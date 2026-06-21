// ================================================
//  Topic   : Vectors - Rotate Array
//  Problem : Rotate array to the right by k steps
//  Leetcode: 189
//  Time    : O(n)  |  Space: O(1)
// ================================================

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

void reverse(vector<int>& v, int l, int r) {
    while (l < r) { swap(v[l++], v[r--]); }
}

// Method 1: Reverse Trick O(n) time, O(1) space
// Right rotate by k:
void rotateRight(vector<int>& v, int k) {
    int n = v.size();
    k = k % n;          // handle k >= n (rotating n times = back to start)
    if (k == 0) return;

    reverse(v, 0, n - k - 1);    // reverse first n-k elements
    reverse(v, n - k, n - 1);    // reverse last k elements
    reverse(v, 0, n - 1);        // reverse whole array
}

// Method 2: Left Rotate by k
void rotateLeft(vector<int>& v, int k) {
    int n = v.size();
    k = k % n;
    if (k == 0) return;

    reverse(v, 0, k - 1);      // reverse first k
    reverse(v, k, n - 1);      // reverse rest
    reverse(v, 0, n - 1);      // reverse whole
}

int main() {

    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
    cout << "Original array(v1): ";
    print(v1);

    rotateRight(v1, 3);
    cout << "Right rotate by 3: ";
    print(v1);    // [5, 6, 7, 1, 2, 3, 4]

    vector<int> v2 = {1, 2, 3, 4, 5, 6, 7};
    cout << "\nOriginal array(v2): ";
    print(v2);

    rotateLeft(v2, 2);
    cout << "Left  rotate by 2: ";
    print(v2);    // [3, 4, 5, 6, 7, 1, 2]

    return 0;
}

/*
 KEY POINTS:
  - Always do k = k % n first (rotating n times = no change)
  - Reverse trick is the most elegant O(n) O(1) solution
  - Right rotate by k ≡ Left rotate by (n-k)
*/