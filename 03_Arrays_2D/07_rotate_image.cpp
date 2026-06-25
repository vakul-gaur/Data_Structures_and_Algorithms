// ====================================================
//  Topic   : 2D Arrays - Rotate Image
//  Problem : Rotate n×n matrix 90° clockwise in-place
//  Leetcode: 48
//  Time    : O(n²)  |  Space: O(1)
// ====================================================

#include <iostream>
using namespace std;

int main() {

    // 1. 90° Clockwise Rotation

    int mat1[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    // Original Matrix
    cout << "Original:\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << mat1[i][j] << " ";
        }
        cout << endl;
    }

    // Transpose
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            swap(mat1[i][j], mat1[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < 3; i++) {
        int left = 0, right = 2;
        while (left < right) {
            swap(mat1[i][left], mat1[i][right]);
            left++;
            right--;
        }
    }

    cout << "\n90 Degree Clockwise:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat1[i][j] << " ";
        }
        cout << endl;
    }

    // 2. 90° Counter Clockwise

    int mat2[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    // Transpose
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            swap(mat2[i][j], mat2[j][i]);
        }
    }

    // Reverse each column
    for (int j = 0; j < 3; j++) {
        int top = 0, bottom = 2;

        while (top < bottom) {
            swap(mat2[top][j], mat2[bottom][j]);
            top++;
            bottom--;
        }
    }

    cout << "\n90 Degree Counter Clockwise:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat2[i][j] << " ";
        }
        cout << endl;
    }

    // 3. 180° Rotation

    int mat3[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    // Reverse row order
    int top = 0, bottom = 2;

    while (top < bottom) {
        for (int j = 0; j < 3; j++) {
            swap(mat3[top][j], mat3[bottom][j]);
        }
        top++;
        bottom--;
    }

    // Reverse each row
    for (int i = 0; i < 3; i++) {
        int left = 0, right = 2;

        while (left < right) {
            swap(mat3[i][left], mat3[i][right]);
            left++;
            right--;
        }
    }

    cout << "\n180 Degree Rotation:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat3[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
 KEY POINTS:
  - 90° Clockwise = Transpose + Reverse each row
  - 90° Anti-Clock = Transpose + Reverse each column
  - 180° = Reverse row order + Reverse each row
  - Both methods are O(n²) time, O(1) space - no extra matrix needed
  - 4 clockwise rotations = back to original
*/