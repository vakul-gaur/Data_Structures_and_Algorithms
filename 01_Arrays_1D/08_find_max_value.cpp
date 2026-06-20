// ==================================================================
//  Topic   : 1D Arrays - Find Maximum Value
//  Concept : Traverse array keeping track of the largest seen so far
//  Time    : O(n)  |  Space: O(1)
// ==================================================================

#include <iostream>
#include <climits>   // for INT_MIN and INT_MAX
using namespace std;

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Method 1: Assume first element is max
    int maxVal = arr[0];
    int maxIdx = 0;

    for (int i = 1; i < n; i++) {  // start from index 1 since 0 is already taken
        if (arr[i] > maxVal) {
            maxVal = arr[i];        // update max if current is bigger
            maxIdx = i;
        }
    }

    cout << "\nMaximum value = " << maxVal << " at index " << maxIdx << endl;

    // Method 2: Start with INT_MIN (works even for all-negative arrays)
    int maxVal2 = INT_MIN;          // smallest possible int value
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxVal2) {
            maxVal2 = arr[i];
        }
    }
    cout << "Max (using INT_MIN) = " << maxVal2 << endl;

    // Also find Minimum
    int minVal = INT_MAX;           // largest possible int value
    for (int i = 0; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    cout << "Minimum value = " << minVal << endl;

    return 0;
}

/*
 KEY POINTS:
  - Start maxVal = arr[0] to handle negative arrays correctly
  - Update max whenever you find a bigger element
  - INT_MIN is the smallest int (~-2.1 billion), safe starting point
  - INT_MAX (from <climits>) is the largest int, use for finding min
  - Single pass O(n) is optimal — you must check every element at least once
*/