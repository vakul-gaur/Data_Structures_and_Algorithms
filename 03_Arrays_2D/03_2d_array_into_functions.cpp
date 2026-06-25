// ===============================================================
//  Topic   : 2D Arrays - Passing to Functions
//  Concept : Column count must be specified in function parameter
// ===============================================================

#include <iostream>
using namespace std;

// Column size (3) must be known at compile time
void printMatrix(int arr[][3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Returns sum of all elements in matrix
int matrixSum(int arr[][3], int rows) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

// Modifies original matrix (no copy is created)
void doubleAll(int arr[][3], int rows) {
    for (int i = 0; i < rows; i++) {            // Multiply every element by 2
        for (int j = 0; j < 3; j++) {
            arr[i][j] *= 2;
        }
    }
}

int main() {

    int mat[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "Original Matrix:\n";
    printMatrix(mat, 2);

    cout << "\nSum = " << matrixSum(mat, 2) << endl;

    doubleAll(mat, 2);

    cout << "\nAfter Doubling:\n";
    printMatrix(mat, 2);

    return 0;
}

/*
 KEY POINTS:
  - f(int arr[][cols], ...) -> cols must be a compile-time constant
  - 2D arrays are not copied when passed - changes affect original
  - Column size is required so the compiler can access matrix elements correctly.
  - For variable sizes, prefer 2D vectors
*/