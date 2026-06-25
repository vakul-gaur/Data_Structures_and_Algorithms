// ============================================================
//  Topic   : 2D Arrays - Representation and Declaration
//  Concept : A matrix is an array of arrays — rows × columns
//            are stored contiguously in memory, row by row
// ============================================================

#include <iostream>
using namespace std;

int main() {

    // Way 1: Declare then assign
    int a[3][3];    // 3 rows, 3 columns — garbage values
    a[0][0] = 1;  a[0][1] = 2;  a[0][2] = 3;
    a[1][0] = 4;  a[1][1] = 5;  a[1][2] = 6;
    a[2][0] = 7;  a[2][1] = 8;  a[2][2] = 9;

    // Way 2: Declare + Initialize together
    int b[2][3] = { {1, 2, 3}, {4, 5, 6} };

    // Way 3: Partial initialization (rest filled with 0)
    int c[3][3] = {{1, 2}, {4}};    // c = {{1,2,0}, {4,0,0}, {0,0,0}}

    // Way 4: All zeros
    int d[3][3] = {0};

    // Way 5: Flat initialization (compiler fills row by row)
    int e[2][3] = {1, 2, 3, 4, 5, 6};

    // Access formula: a[row][col]  — row and col both 0-indexed
    cout << "Matrix a\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

/*
 KEY POINTS:
  - Declaration: int arr[ROWS][COLS]
  - Access: arr[row][col]  — row and col both 0-indexed
  - C++ stores 2D arrays in row by row order in memory
  - ROWS can be omitted if initializing: int arr[][3] = {...}
*/