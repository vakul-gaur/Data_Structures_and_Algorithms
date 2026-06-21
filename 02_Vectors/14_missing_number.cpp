// ================================================================================
//  Topic   : Vectors - Missing Number
//  Problem : Array has n distinct numbers in range [0, n]. Find the missing one.
//  Leetcode: 268
//  Time    : O(n)  |  Space: O(1)
// ================================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Method 1: Sum Formula O(n) O(1)
// Expected sum of 0..n = n*(n+1)/2
// Missing = expected - actual sum
int missingSum(vector<int>& v) {
    int n = v.size();
    int expected = n * (n + 1) / 2;
    int actual = 0;
    for (int x : v) actual += x;
    return expected - actual;
}

// Method 2: XOR O(n) O(1)
// a ^ a = 0, a ^ 0 = a
// XOR all indices 0..n with all values -> only missing number remains
int missingXOR(vector<int>& v) {
    int n = v.size();
    int xorVal = 0;

    for (int i = 0; i <= n; i++) xorVal ^= i;         // XOR all indices
    for (int x : v) xorVal ^= x;                      // XOR all values

    return xorVal;  // paired numbers cancel out, only missing survives
}

// Method 3: Sort and scan O(n log n) O(1)
int missingSort(vector<int> v) {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != i) return i;   // expected i but found something else
    }
    return v.size();  // missing the last number n
}

int main() {

    vector<int> v1 = {3, 0, 1};
    cout << "Array: "; for (int x : v1) cout << x << " ";
    cout << "\nSum Formula: " << missingSum(v1);    // 2
    cout << "\nXOR Method: " << missingXOR(v1);     // 2
    cout << "\nSort Method: " << missingSort(v1);   // 2

    vector<int> v2 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << "\n\nArray: "; for (int x : v2) cout << x << " ";
    cout << "\nMissing: " << missingSum(v2) << endl;    // 8

    return 0;
}

/*
 KEY POINTS:
  - Sum formula: fastest to code, O(n) O(1), watch for integer overflow (use long long for large n)
  - XOR: elegant, no overflow risk, O(n) O(1)
    -> every present number appears twice (once in index, once in value), cancels to 0
    -> missing number appears only once -> survives
  - Sort: simplest to understand but O(n log n)
*/