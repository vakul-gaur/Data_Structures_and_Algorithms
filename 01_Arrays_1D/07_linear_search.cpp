// ==================================================================
//  Topic   : 1D Arrays - Linear Search
//  Concept : Search for a target value one by one from left to right
//  Time    : O(n)  |  Space: O(1)
// ==================================================================

#include <iostream>
using namespace std;

// Returns index of target if found, else -1
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;       // found at index i
        }
    }
    return -1;              // not found
}

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    // Search for the target element
    int result = linearSearch(arr, n, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    // Count occurrences (if duplicates exist)
    int count = 0;
    cout << "\nAll positions of " << target << ": ";
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << i << " ";
            count++;
        }
    }
    if (count == 0) cout << "None";
    cout << "\nTotal count: " << count << endl;

    return 0;
}

/*
 KEY POINTS:
  - Linear search checks every element one by one
  - Best case  O(1): element is at index 0
  - Worst case O(n): element is at the end or not present
  - Works on UNSORTED arrays
  - Return -1 as value to indicate "not found"
*/