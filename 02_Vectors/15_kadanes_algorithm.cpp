// ========================================================
//  Topic   : Vectors - Kadane's Algorithm
//  Problem : Find the maximum sum subarray (contiguous)
//  Leetcode: 53 (Maximum Subarray)
//  Time    : O(n)  |  Space: O(1)
// ========================================================

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// At each position, decide whether to start fresh or extend the current subarray
// currentSum = max(v[i], currentSum + v[i])
int kadane(vector<int>& v) {
    int currentSum = v[0];      // max sum ending at current position
    int maxSum = v[0];      // global max found so far

    for (int i = 1; i < v.size(); i++) {
        // Either extend previous subarray or start new one here
        currentSum = max(v[i], currentSum + v[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

// Kadane's with subarray indices (track start and end)
int kadaneWithIndices(vector<int>& v, int& start, int& end) {
    int currentSum = v[0];
    int maxSum = v[0];
    int tempStart = 0;
    start = 0; end = 0;

    for (int i = 1; i < (int)v.size(); i++) {
        if (v[i] > currentSum + v[i]) {
            // starting fresh is better
            currentSum = v[i];
            tempStart = i;
        } else {
            currentSum += v[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }
    return maxSum;
}

// Brute Force O(n^2) for comparison
int bruteForce(vector<int>& v) {
    int maxSum = INT_MIN;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += v[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

int main() {

    vector<int> v1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Array: ";
    for (int x : v1) cout << x << ", ";
    cout << endl;

    cout << "Kadane's Max Sum: " << kadane(v1) << endl;       // 6
    cout << "Brute Force: " << bruteForce(v1) << endl;   // 6

    // All negatives
    vector<int> v2 = {-3, -1, -4, -2};
    cout << "\nAll negative {-3,-1,-4,-2}: " << kadane(v2) << endl;  // -1

    // All positives
    vector<int> v3 = {1, 2, 3, 4, 5};
    cout << "All positive {1,2,3,4,5}: " << kadane(v3) << endl;   // 15

    return 0;
}

/*
 KEY POINTS:
  - Kadane's is the classic dynamic programming / greedy problem
  - currentSum = max(v[i], currentSum + v[i])
    -> if adding v[i] makes things worse, just start fresh from v[i]
  - Global max tracks the best seen so far
  - Works for all-negative arrays: returns the least negative (single element)
  - O(n) single pass - optimal, cannot do better
  - Subarray indices: track tempStart, update start/end only when new max found
*/