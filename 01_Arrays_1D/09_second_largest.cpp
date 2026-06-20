// ====================================================
//  Topic   : 1D Arrays - Second Largest Element
//  Concept : Find the second largest value in one pass
//  Time    : O(n)  |  Space: O(1)
// ====================================================

#include <iostream>
#include <climits>
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

    // Method 1: Two-variable single pass (Optimal)
    int first  = INT_MIN;   // largest
    int second = INT_MIN;   // second largest

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;     // old max becomes second
            first  = arr[i];    // new element is the new max
        }
        else if (arr[i] > second && arr[i] != first) {
            // bigger than second but not equal to first (distinct values)
            second = arr[i];
        }
    }

    if (second == INT_MIN) {
        cout << "No second largest element (all elements may be equal)." << endl;
    } else {
        cout << "Largest = " << first  << endl;
        cout << "Second Largest = " << second << endl;
    }

    // Method 2: Sort-based (easier but O(n log n))
    // Sort descending and pick the first element != arr[0]

    return 0;
}

/*
 KEY POINTS:
  - Maintain TWO variables: first (max) and second (2nd max)
  - arr[i] != first ensures we look for DISTINCT second largest
    e.g. [5, 5, 3] -> second largest is 3, not 5 again
  - If all elements are the same, second stays INT_MIN -> handle that case
  - This is O(n) - more efficient than sorting O(n log n)
*/