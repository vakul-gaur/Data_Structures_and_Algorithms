// =====================================================================
//  Topic   : 2D Arrays - Add Two Matrices
//  Concept : Element-wise addition, matrices must have same dimensions
//  Time    : O(n*m)  |  Space: O(n*m) for result
// =====================================================================

#include <iostream>
using namespace std;

int main() {

    int A[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    int B[3][3] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };

    int result[3][3];

    // Add corresponding elements
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "Result Matrix:\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
 KEY POINTS:
  - Matrix addition: A[i][j] + B[i][j] for all i, j
  - REQUIREMENT: both matrices must have identical dimensions (same rows and cols)
  - Result matrix has the same dimensions as inputs
  - Subtraction and scalar multiplication follow the same element-wise pattern
*/