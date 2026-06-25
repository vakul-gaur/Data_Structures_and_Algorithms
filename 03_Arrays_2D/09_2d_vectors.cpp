// =======================================================================
//  Topic   : 2D Vectors - Basics, Declaration, I/O, Passing to Functions
//  Concept : vector< vector<int> > — dynamic 2D array, no fixed size
// =======================================================================

#include <iostream>
#include <vector>
using namespace std;

// Function to print a 2D vector
void printMatrix(const vector<vector<int>>& mat) {  // use & -> Pass by reference to avoid copying

    int rows = mat.size();
    int cols = mat[0].size();

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << "\t";
        }

        cout << "\n";
    }
}

int main() {

    // Declaration (3 rows × 4 cols, all values = 0)
    vector<vector<int>> mat(3, vector<int>(4, 0));

    // Input
    int rows, cols;
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));

    cout << "Enter elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    // Output using function
    cout << "\nMatrix:\n";
    printMatrix(grid);

    // Accessing elements
    cout << "\nFirst Element = " << grid[0][0] << "\n";

    // Size information
    cout << "Rows = " << grid.size() << "\n";
    cout << "Cols = " << grid[0].size() << "\n";

    return 0;
}

/*
 KEY POINTS:
  - vector< vector<int> > is a dynamic 2D structure - rows can have different lengths
  - vector< vector<int> > v(rows, vector<int>(cols, val)) -> uniform initialization
  - Pass by ref for modification: vector<vector<int>>&
  - v.size() = number of rows; v[i].size() = number of cols in row i
  - Much more flexible than int arr[MAXN][MAXN] — no need to declare max size
*/