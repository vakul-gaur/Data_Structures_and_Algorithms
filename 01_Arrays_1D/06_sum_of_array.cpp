// ============================================================
//  Topic   : 1D Arrays - Sum of Array
//  Concept : Calculate sum and average of all array elements
// ============================================================

#include <iostream>
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

    // Calculate Sum of array
    int sum = 0;                   
    for (int i = 0; i < n; i++) {
        sum += arr[i];              // keep adding each element
    }

    cout << "\nSum of array     = " << sum << endl;

    // Calculate Average of array
    float avg = (float)sum / n;    // cast to float to avoid integer division
    cout << "Average of array = " << avg << endl;

    return 0;
}

/*
 KEY POINTS:
  - Initialize sum = 0 before the loop (not garbage value)
  - Use long long instead of int if values can be very large
  - Average = sum / count  (use double/float to get decimal result)
  - (float)sum / n  -> correct;  sum / n  alone does integer division
*/