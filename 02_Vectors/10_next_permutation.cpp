// ==========================================================================
//  Topic   : Vectors - Next Permutation
//  Problem : Rearrange into the lexicographically next greater permutation
//  Leetcode: 31
//  Time    : O(n)  |  Space: O(1)
// ==========================================================================

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

// Next Permutation Algorithm
// Step 1: Find the rightmost element that is less than its next element (pivot)
// Step 2: Find the smallest element to the right of pivot that is greater than pivot
// Step 3: Swap them
// Step 4: Reverse the suffix after pivot's original position
void nextPermutation(vector<int>& v) {
    int n = v.size();

    // Step 1: find pivot (largest index i such that v[i] < v[i+1])
    int pivot = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] < v[i + 1]) {
            pivot = i;
            break;
        }
    }

    // If no pivot found -> array is in descending order -> already last permutation
    if (pivot == -1) {
        reverse(v.begin(), v.end());    // reverse to get first permutation
        return;
    }

    // Step 2: find rightmost element > v[pivot] in suffix
    for (int j = n - 1; j > pivot; j--) {
        if (v[j] > v[pivot]) {
            swap(v[pivot], v[j]);       // Step 3: swap
            break;
        }
    }

    // Step 4: reverse suffix after pivot
    reverse(v.begin() + pivot + 1, v.end());
}

int main() {

    vector<int> v1 = {1, 2, 3, 4};
    cout << "Original vector: ";
    print(v1);

    nextPermutation(v1);
    cout << "Next Permutation: ";
    print(v1);

    cout << endl;

    // All permutations of {1,2,3,4}
    vector<int> v2 = {1, 2, 3, 4};
    int n = v2.size();
    cout << "All permutations of {1,2,3,4}:\n";

    int total = 1;
    for (int i = 2; i <= n; i++) {
        total *= i;
    }

    while (total--) {
        cout << "  ";
        print(v2);
        nextPermutation(v2);
    }

    cout << endl;
    
    return 0;
}

/*
 KEY POINTS:
  - Pivot: largest index where v[i] < v[i+1]  (find from right)
  - If no pivot: array is fully descending = last permutation, reverse to get first
  - Swap pivot with the rightmost element greater than it
  - Reverse the suffix after pivot to get the smallest possible arrangement
*/