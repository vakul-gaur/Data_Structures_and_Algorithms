// ==================================================================
//  Topic   : 2D Arrays - Input, Output and Traversal
//  Concept : Taking user input, printing, row/col/diagonal traversal
// ==================================================================

#include <iostream>
using namespace std;

int main() {

    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    int arr[10][10];    // max 10x10 for static array

    // Input: nested loop row by row
    cout << "Enter elements row by row:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    // Output: print as matrix
    cout << "\nMatrix\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }

    // Row-wise traversal
    cout << "\nRow-wise\n";
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    // Column-wise traversal
    cout << "\nColumn-wise\n";
    for (int j = 0; j < cols; j++) {
        cout << "Col " << j << ": ";
        for (int i = 0; i < rows; i++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    // Diagonal traversal (only for square matrix)
    if (rows == cols) {
        cout << "\nMain Diagonal (top-left to bottom-right)\n";
        for (int i = 0; i < rows; i++)
            cout << arr[i][i] << " ";
        cout << "\n";

        cout << "\nAnti-Diagonal (top-right to bottom-left)\n";
        for (int i = 0; i < rows; i++)
            cout << arr[i][cols - 1 - i] << " ";
        cout << "\n";
    }

    return 0;
}

/*
 KEY POINTS:
  - Outer loop -> rows (i), Inner loop -> columns (j)
  - Swap loops to switch between row-wise and column-wise traversal
  - Main diagonal: arr[i][i] (only when rows == cols)
  - Anti-diagonal: arr[i][cols-1-i]
*/