// ==============================================================
//  Topic   : 2D Arrays - Matrix Multiplication
//  Concept : A(m×k) × B(k×n) = C(m×n)
//            C[i][j] = dot product of row i of A and col j of B
//  Time    : O(m * k * n)  |  Space: O(m*n) for result
// ==============================================================

#include <iostream>
using namespace std;

int main() {

    // A = 2 × 3
    int A[2][3] = { {1, 2, 3}, {4, 5, 6} };

    // B = 3 × 2
    int B[3][2] = { {7, 8}, {9, 10}, {11, 12} };

    // Result = 2 × 2
    int result[2][2] = {0};

    // Matrix Multiplication
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            // Dot product of row i and column j
            for (int k = 0; k < 3; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "A x B:\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
 KEY POINTS:
  - A(m×k) × B(k×n) -> result is (m×n)
  - Rule: A's columns must equal B's rows (the inner dimension k must match)
  - C[i][j] = sum of A[i][p] * B[p][j] for p = 0..k-1
  - Matrix multiplication is not commutative: A×B ≠ B×A in general
  - Identity matrix I: A×I = I×A = A
  - Time complexity: O(n³) for n×n matrices
*/