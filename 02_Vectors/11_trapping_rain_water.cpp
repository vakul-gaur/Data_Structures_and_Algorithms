// ============================================================
//  Topic   : Vectors - Trapping Rain Water
//  Problem : Given elevation heights, find total water trapped
//  Leetcode: 42
//  Time    : O(n)  |  Space: O(1) for optimal
// ============================================================

#include <iostream>
#include <vector>
using namespace std;

// Method 1: Precompute left max and right max arrays O(n) space
int ExtraSpace(vector<int>& h) {
    int n = h.size();
    if (n == 0) return 0;

    vector<int> leftMax(n), rightMax(n);

    leftMax[0] = h[0];
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i - 1], h[i]);     // max height from left up to i

    rightMax[n - 1] = h[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rightMax[i] = max(rightMax[i + 1], h[i]);   // max height from right up to i

    // Water at index i = min(leftMax, rightMax) - height[i]
    int water = 0;
    for (int i = 0; i < n; i++) {
        water += min(leftMax[i], rightMax[i]) - h[i];
    }
    return water;
}

// Method 2: Two Pointer O(1) space (Optimal)
int TwoPointer(vector<int>& h) {
    int left = 0, right = h.size() - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left < right) {
        if (h[left] < h[right]) {
            // left side is the restriction
            if (h[left] >= leftMax) leftMax = h[left];
            else water += leftMax - h[left];    // trapped water at left
            left++;
        } else {
            // right side is the restriction
            if (h[right] >= rightMax) rightMax = h[right];
            else water += rightMax - h[right];  // trapped water at right
            right--;
        }
    }
    return water;
}

int main() {
    vector<int> h1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};  // water trapped = 6 units
    cout << "Heights: ";
    for (int x : h1) cout << x << " ";
    cout << "\nWater trapped (extra space): " << ExtraSpace(h1) << endl;
    cout << "Water trapped (two pointer): " << TwoPointer(h1) << endl;

    // Another test cases
    vector<int> h2 = {4, 2, 0, 3, 2, 5};
    cout << "\nHeights: ";
    for (int x : h2) cout << x << " ";
    cout << "\nWater trapped: " << TwoPointer(h2) << endl;   // 9

    vector<int> h3 = {3, 0, 3};
    cout << "\n{3,0,3} water = " << TwoPointer(h3) << endl;   // 3

    vector<int> h4 = {1, 2, 3};
    cout << "{1,2,3} water = " << TwoPointer(h4) << endl;     // 0 (no trap)

    return 0;
}

/*
 KEY POINTS:
  - Water at position i = min(maxLeft, maxRight) - height[i]
  - Extra space: precompute leftMax[] and rightMax[] arrays
  - Two pointer: track leftMax and rightMax, process smaller side first
    -> If h[left] < h[right]: left side limits water -> process left
    -> Else: right side limits water -> process right
*/