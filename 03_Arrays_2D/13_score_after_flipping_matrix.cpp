// ==============================================================
//  Topic   : 2D Arrays - Score After Flipping Matrix
//  Problem : Maximize binary matrix score by flipping rows/cols
//  Leetcode: 861
//  Time    : O(n*m)  |  Space: O(1) in-place
// ==============================================================

#include <iostream>
#include <vector>
using namespace std;

// Greedy Approach
// Key Insight:
// 1. The leftmost bit (MSB) contributes most to score (2^(cols-1))
//    -> ALWAYS flip any row where MSB = 0 to make it 1
// 2. For each column (after step 1), count 1s and 0s
//    -> If 0s > 1s in a column, flip that column (more 1s = higher score)

int matrixScore(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Step 1: Ensure every row starts with 1 (flip row if grid[i][0] == 0)
    for (int i = 0; i < rows; i++) {
        if (grid[i][0] == 0) {
            for (int j = 0; j < cols; j++)
                grid[i][j] ^= 1;    // XOR with 1 flips the bit
        }
    }

    // Step 2: For each column, maximize 1s (skip col 0 already handled)
    for (int j = 0; j < cols; j++) {
        int c0 = 0, c1 = 0;
        for (int i = 0; i < rows; i++) {
            if (grid[i][j] == 0) c0++;
            else c1++;
        }
        if (c0 > c1) {
            for (int i = 0; i < rows; i++) {
                grid[i][j] ^= 1;       // grid[i][j] = 1 - grid[i][j]; -> this also works to flip the bit (0/1)
            }
        }
    }

    // Step 3: Calculate score (each row is a binary number)
    int score = 0;
    for (int i = 0; i < rows; i++) {
        int val = 0;
        for (int j = 0; j < cols; j++) {
            val = val * 2 + grid[i][j];    // Convert binary row to decimal
        }
        score += val;
    }

    return score;
}

// Function to print the grid
void printGrid(const vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << "= ";

        // Convert binary row to decimal
        int val = 0;
        for (int j = 0; j < grid[i].size(); j++) {
            val = val * 2 + grid[i][j];
        }
        cout << val << "\n";
    }
}

int main() {

    vector<vector<int>> grid = { {0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0} };

    cout << "Original Grid:\n";
    printGrid(grid);

    int result = matrixScore(grid);

    cout << "\nAfter Greedy Flips:\n";
    printGrid(grid);

    cout << "\nMax Score = " << result << "\n";

    return 0;
}

/*
 KEY POINTS:
  - Greedy: always safe to flip row if first column is 0 (MSB should be 1)
  - After ensuring all MSBs are 1, maximize each column independently
  - Flip column j if it has more 0s than 1s (flipping gains more 1s)
  - XOR with 1 flips a bit: 0^1=1, 1^1=0
  - Binary conversion: val = val * 2 + grid[i][j]
  - MSB contributes 2^(cols-1) -> most impactful bit to keep as 1
*/