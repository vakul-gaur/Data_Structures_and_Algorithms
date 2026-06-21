// ===============================================================
//  Topic   : Vectors - Two Sum
//  Problem : Find two indices such that arr[i] + arr[j] == target
//  Leetcode: 1 (Classic problem)
// ===============================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Method 1: Brute Force O(n^2)
vector<int> twoSumBrute(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {-1, -1};    // no pair found
}

// Method 2: Two Pointer O(n log n) — only if indices not needed
// Sort + two pointer finds values (not original indices)
vector<int> twoSumTwoPointer(vector<int> nums, int target) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) return {nums[left], nums[right]};
        else if (sum < target) left++;
        else right--;
    }
    return {-1, -1};
}

int main() {

    vector<int> nums = {2, 1, 11, 7};
    int target = 9;

    cout << "Array: ";
    for (int x : nums) cout << x << " ";
    cout << "\nTarget: " << target << "\n";

    // Brute Force
    vector<int> v1 = twoSumBrute(nums, target);
    cout << "\nBrute Force Result: [" << v1[0] << ", " << v1[1] << "]";

    // Two Pointer
    vector<int> v2 = twoSumTwoPointer(nums, target);
    cout << "\nTwo Pointer (values): [" << v2[0] << ", " << v2[1] << "]";

    return 0;
}

/*
 KEY POINTS:
  - Brute force: check every pair -> O(n^2) time, O(1) space
  - Two pointer: sort then squeeze -> O(n log n) time, O(1) space (loses original indices)
*/