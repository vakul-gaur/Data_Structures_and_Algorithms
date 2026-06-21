// ====================================================
//  Topic   : Vectors - Dutch National Flag Algorithm
//  Problem : Sort array of 0s, 1s, and 2s in one pass
//  Leetcode: 75 (Sort Colors)
//  Time    : O(n) | Space: O(1)
// ====================================================

#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

// Dutch National Flag (3-pointer approach)
// lo  : everything before lo is 0
// mid : current element being processed
// hi  : everything after hi is 2

void sortColors(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) {

        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);       // 0 goes to front
            low++;
            mid++;
        }

        else if (nums[mid] == 1) {
            mid++;                            // 1 is already in right place, just move on
        }

        else {                                // nums[mid] == 2
            swap(nums[mid], nums[high]);      // 2 goes to back
            high--;
            // DON'T increment mid — the swapped element from hi needs to be checked
        }
    }
}

int main() {

    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Original array: ";
    print(nums);

    sortColors(nums);

    cout << "Sorted array: ";
    print(nums);

    return 0;
}

/*
 KEY POINTS:
  - 3 pointers: lo (0 boundary), mid (current), hi (2 boundary)
  - v[mid]==0: swap with lo, both lo and mid ++
  - v[mid]==1: just  mid ++
  - v[mid]==2: swap with hi, ONLY hi --
  - Single pass O(n), no extra space O(1)
  - Named after the Netherlands flag: red (0), white (1), blue (2)
*/