// ================================================================
//  Topic   : 2D Arrays - Spiral Matrix
//  Problem : Print matrix in spiral order (clockwise from outside)
//  Leetcode: 54 Spiral Matrix
//  Time    : O(n*m)  |  Space: O(1) extra
// ================================================================

#include <iostream>
#include <vector>
using namespace std;

// Spiral Order using 4 boundaries
vector<int> spiralOrder(vector<vector<int>>& mat) {
    vector<int> res;
    int m = mat.size();
    int n = mat[0].size();

    int minr = 0, maxr = m - 1;
    int minc = 0, maxc = n - 1;

    while (minr <= maxr && minc <= maxc) {

        // left -> right
        for (int j = minc; j <= maxc; j++)
            res.push_back(mat[minr][j]);
        minr++;

        // top -> bottom
        for (int i = minr; i <= maxr; i++)
            res.push_back(mat[i][maxc]);
        maxc--;

        // right -> left
        if (minr <= maxr) {
            for (int j = maxc; j >= minc; j--)
                res.push_back(mat[maxr][j]);
            maxr--;
        }

        // bottom -> top
        if (minc <= maxc) {
            for (int i = maxr; i >= minr; i--)
                res.push_back(mat[i][minc]);
            minc++;
        }
    }

    return res;
}

// Generate Spiral Matrix (fill numbers in spiral order)
// Leetcode 59 (Spiral Matrix II)

vector<vector<int>> generateSpiral(int n) {
    vector<vector<int>> mat(n, vector<int>(n));

    int minr = 0, maxr = n - 1;
    int minc = 0, maxc = n - 1;
    int val = 1;

    while (minr <= maxr && minc <= maxc) {

        // left -> right
        for (int j = minc; j <= maxc; j++)
            mat[minr][j] = val++;
        minr++;

        // top -> bottom
        for (int i = minr; i <= maxr; i++)
            mat[i][maxc] = val++;
        maxc--;

        // right -> left
        if (minr <= maxr) {
            for (int j = maxc; j >= minc; j--)
                mat[maxr][j] = val++;
            maxr--;
        }

        // bottom -> top
        if (minc <= maxc) {
            for (int i = maxr; i >= minr; i--)
                mat[i][minc] = val++;
            minc++;
        }
    }

    return mat;
}

int main() {

    vector<vector<int>> mat1 = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9,10,11,12}, {13,14,15,16} };

    cout << "Matrix:\n";
    for (int i = 0; i < mat1.size(); i++) {
        for (int j = 0; j < mat1[i].size(); j++) {
            cout << mat1[i][j] << "\t";
        }
        cout << "\n";
    }

    vector<int> ans = spiralOrder(mat1);

    cout << "\nSpiral order:\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    // Non-square matrix
    vector<vector<int>> mat2 = { {1,2,3},{4,5,6} };

    cout << "\nMatrix 2x3:\n";
    for (int i = 0; i < mat2.size(); i++) {
        for (int j = 0; j < mat2[i].size(); j++) {
            cout << mat2[i][j] << "\t";
        }
        cout << "\n";
    }

    vector<int> ans2 = spiralOrder(mat2);

    cout << "\n2x3 Spiral:\n";
    for (int i = 0; i < ans2.size(); i++) {
        cout << ans2[i] << " ";
    }
    cout << "\n";

    // Generated spiral
    cout << "\nGenerated Spiral (n=4):\n";
    vector<vector<int>> gen = generateSpiral(4);

    for (int i = 0; i < gen.size(); i++) {
        for (int j = 0; j < gen[i].size(); j++) {
            cout << gen[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}

/*
 KEY POINTS:
  - 4 boundaries: top, bottom, left, right
  - Each traversal step shrinks the corresponding boundary inward
  - Must check (top <= bottom) and (left <= right) before left and up traversals 
    to avoid processing same row/col twice for odd-dimension matrices
  - Pattern: RIGHT -> DOWN -> LEFT -> UP -> repeat
  - Works for both square and rectangular matrices
  - Generate spiral: same boundaries, just fill incrementing number
*/