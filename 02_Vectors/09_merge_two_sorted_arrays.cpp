// ==========================================================
//  Topic   : Vectors - Merge Two Sorted Arrays
//  Problem : Merge two sorted arrays into one sorted array
//  Leetcode: 88 (Merge Sorted Array)
//  Time    : O(m + n)  |  Space: O(m + n)
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

// Method 1: Two Pointer Merge (classic merge sort step)
vector<int> mergeSorted(vector<int>& a, vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;

    // pick the smaller of the two front elements each time
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) result.push_back(a[i++]);
        else result.push_back(b[j++]);
    }

    // one array can have leftover elements
    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);

    return result;
}

// Method 2: Merge into first array in-place (Leetcode #88 style)
// a has size m+n with extra space at the end; b has size n
// Fill from the back to avoid overwriting elements
void mergeInPlace(vector<int>& a, int m, vector<int>& b, int n) {
    int i = m - 1;          // last real element of a
    int j = n - 1;          // last element of b
    int k = m + n - 1;      // last position in merged result (end of a)

    while (i >= 0 && j >= 0) {
        if (a[i] >= b[j]) a[k--] = a[i--];
        else a[k--] = b[j--];
    }

    // copy remaining from b (if a was exhausted first)
    while (j >= 0) a[k--] = b[j--];
    // no need to copy remaining from a (already in place)
}

int main() {

    // Method 1: merge into new array
    vector<int> a = {1, 3, 5, 6};
    vector<int> b = {2, 4, 7, 8, 9, 10};
    cout << "Merged array: ";
    print(mergeSorted(a, b));

    // Method 2: in-place merge
    // a = [1,3,5,0,0,0] where 0s are reserved space, m=3
    // b = [2,4,6], n=3
    vector<int> g = {1, 3, 5, 0, 0, 0};
    vector<int> h = {2, 4, 6};
    mergeInPlace(g, 3, h, 3);
    cout << "In-place merge result: ";
    print(g);

    return 0;
}

/*
 KEY POINTS:
  - In two pointer -> compare front elements of both arrays, pick the smaller one
  - After main loop, one array might still have elements — copy them all
  - Time: O(m + n)  |  Space: O(m+n) for method 1, O(1) for method 2
*/