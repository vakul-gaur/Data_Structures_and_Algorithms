// ============================================================
//  Topic   : 2D Arrays - Maximum Element
//  Concept : Find global max, row-wise max, column-wise max
//  Time    : O(n*m)  |  Space: O(1)
// ============================================================

#include <iostream>
#include <climits>
using namespace std;

int main() {

    int rows = 3, cols = 4;
    int mat[3][4] = { { 3, 15,  2,  7}, {12,  1, 19,  4}, { 8, 11,  5, 20} };

    // Print matrix
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << mat[i][j] << "\t";
        cout << "\n";
    }

    // Maximum
    int max = INT_MIN;
    int maxRow = 0, maxCol = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] > max) {
                max = mat[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
    cout << "\nMaximum = " << max;

    // Minimum
    int min = INT_MAX;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (mat[i][j] < min) min = mat[i][j];
    cout << "\nMinimum = " << min << "\n";

    return 0;
}

/*
 KEY POINTS:
  - Use <climits> for INT_MIN and INT_MAX
  - Initialize max with INT_MIN (not 0) to handle negative matrices
  - Initialize min with INT_MAX
  - Track indices (maxRow, maxCol) to know where the max is
*/