// ================================================================
//  Topic   : 2D Arrays - Search in Matrix
//  Problem : Matrix sorted row-wise and column-wise. Find target.
//  Leetcode: 240 (Search a 2D Matrix II)
//  Time    : O(n + m)  |  Space: O(1)
// ================================================================

#include <iostream>
#include <vector>
using namespace std;

// Brute Force O(n*m)
bool searchBrute(vector<vector<int>>& mat, int target) {
    int rows = mat.size(), cols = mat[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}

// Binary Search per row O(n log m)
bool searchBinaryPerRow(vector<vector<int>>& mat, int target) {
    int rows = mat.size(), cols = mat[0].size();
    for (int i = 0; i < rows; i++) {
        int lo = 0, hi = cols - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mat[i][mid] == target) return true;
            else if (mat[i][mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return false;
}

// Staircase Search O(n + m) — Optimal
// Start from top-right corner:
//   - If current == target -> found!
//   - If current > target -> move left (eliminate column)
//   - If current < target -> move down (eliminate row)
bool searchMatrix(vector<vector<int>>& mat, int target) {

    int rows = mat.size(), cols = mat[0].size();
    int row = 0;
    int col = cols - 1;     // start at top-right corner

    while (row < rows && col >= 0) {
        if (mat[row][col] == target) {
            return true;    // return {row, col} if position is needed
        } else if (mat[row][col] > target) {
            col--;          // too big -> go left
        } else {
            row++;          // too small -> go down
        }
    }
    return false;    // return {-1, -1} if position is needed
}

int main() {

    vector<vector<int>> mat = {
        {1,  4,  7, 11, 15},
        {2,  5,  8, 12, 19},
        {3,  6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int rows = mat.size();
    int cols = mat[0].size();

    // Print Matrix
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << "\n";
    }

    // Targets to search
    vector<int> targets = {5, 20, 30, 1, 50};

    cout << "\nSearch Results (Staircase Search):\n";

    for (int i = 0; i < targets.size(); i++) {
        int target = targets[i];

        if (searchMatrix(mat, target)) {
            cout << target << " -> FOUND\n";
        }
        else {
            cout << target << " -> NOT FOUND\n";
        }
    }

    return 0;
}

/*
 KEY POINTS:
  - Every row and column is sorted in ascending order
  - Brute force O(n*m): check every cell
  - Binary per row O(n log m): decent, but not optimal
  - Staircase O(n+m): start at top-right corner (or bottom left — both work)
    -> TOP-RIGHT: go left if too big, go down if too small
    -> BOTTOM-LEFT: go right if too small, go up if too big
  - Each step eliminates a full row or full column
  - Only n+m steps in worst case -> very efficient
*/
