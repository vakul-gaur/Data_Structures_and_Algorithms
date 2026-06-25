// ========================================================
//  Topic   : 2D Arrays - Wave Matrix Traversal
//  Concept : Print matrix column by column / row by row:
// ========================================================

#include <iostream>
#include <vector>
using namespace std;

// Column-wise Wave (standard wave print)
// Even cols: top to bottom
// Odd  cols: bottom to top
void waveTraversalByCol(const vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    cout << "Wave (column-wise): ";
    for (int j = 0; j < cols; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < rows; i++)      // Even column: top to bottom
                cout << mat[i][j] << " ";
        } else {
            for (int i = rows - 1; i >= 0; i--)     // Odd column: bottom to top
                cout << mat[i][j] << " ";
        }
    }
    cout << "\n";
}

// Row-wise Wave
// Even rows: left to right
// Odd  rows: right to left
void waveTraversalByRow(const vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    cout << "Wave (row-wise):    ";
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < cols; j++)
                cout << mat[i][j] << " ";
        } else {
            for (int j = cols - 1; j >= 0; j--)
                cout << mat[i][j] << " ";
        }
    }
    cout << "\n";
}

int main() {

    vector<vector<int>> mat = { { 1,  2,  3,  4}, { 5,  6,  7,  8}, { 9, 10, 11, 12}, {13, 14, 15, 16} };

    cout << "Matrix:\n";
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++){
             cout << mat[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";

    waveTraversalByCol(mat);

    waveTraversalByRow(mat);

    return 0;
}

/*
 KEY POINTS:
  - Wave print = zigzag traversal either column-wise or row-wise
  - Column wave: even col -> top-to-bottom, odd col -> bottom-to-top
  - Row wave: even row -> left-to-right, odd row -> right-to-left
  - Use j % 2 == 0 to check even/odd column
*/
