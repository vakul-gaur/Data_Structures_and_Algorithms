// =======================================================================
//  Topic   : 2D Arrays - Transpose Matrix
//  Problem : Flip matrix over its main diagonal: mat[i][j] -> mat[j][i]
//  Leetcode: 867 Transpose Matrix
//  Time    : O(n*m)  |  Space: O(1) for square matrix
// =======================================================================

#include <iostream>
using namespace std;

int main() {

// In-place Transpose (only for square matrices)
// Swap mat[i][j] with mat[j][i] across the main diagonal (i == j) to avoid double-swapping

    int matA[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    cout << "Original Square Matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matA[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            swap(matA[i][j], matA[j][i]);
        }
    }

    cout << "\nTransposed Square Matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matA[i][j] << " ";
        }
        cout << endl;
    }

// Transpose into new matrix (works for non-square too)
// If A is m×n, then A^T is n×m

    int matB[2][3] = { {1, 2, 3}, {4, 5, 6} };

    int transposed[3][2];

    cout << "\nOriginal Rectangular Matrix:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matB[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            transposed[j][i] = matB[i][j];
        }
    }

    cout << "\nTransposed Rectangular Matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
 KEY POINTS:
  - Transpose: mat[i][j] = mat[j][i]  (reflect across main diagonal)
  - In-place: swap only upper triangle (j > i) to avoid double-swapping
  - Non-square: need a separate destination matrix, dimensions flip (m×n -> n×m)
  - (A^T)^T = A  (transposing twice gives original)
*/